#########################################################################################################
#########################################################################################################
## Ntuple production for bbbar cross section early measurement
## Mika Vesterinen, Greig Cowan
## 24th February 2015
#########################################################################################################
#########################################################################################################

import GaudiKernel.SystemOfUnits as Units
from Gaudi.Configuration import *
from PhysSelPython.Wrappers import AutomaticData, Selection, SelectionSequence
from Configurables import FilterDesktop
from Configurables import DaVinci
from Configurables import DecayTreeTuple
from Configurables import TupleToolDecay
from Configurables import GaudiSequencer
from Configurables import CombineParticles
from Configurables import CondDB
from Configurables import LoKi__Hybrid__TupleTool
from Configurables import LoKi__Hybrid__TupleTool
from Configurables import LoKi__Hybrid__EvtTupleTool
from Configurables import MCTupleToolHierarchy
from Configurables import TupleToolMCTruth
from Configurables import TupleToolMCBackgroundInfo
from Configurables import TupleToolTISTOS, TriggerTisTos

EVTMAX = -1
MODE = "2015"
YEAR = "2015"
OUTPUTLEVEL = ERROR

input_loc = {}

if YEAR == '2015':
	input_loc['Dp']     = 'Phys/B2DMuNuX_DpLine/Particles'
	input_loc['D0']     = 'Phys/B2DMuNuX_D0Line/Particles'
	input_loc['Ds']     = 'Phys/B2DMuNuX_DsLine/Particles'
	input_loc['Lc']     = 'Phys/B2DMuNuX_LcLine/Particles'
	input_loc['D0e']    = 'Phys/B2DMuNuX_D0eLine/Particles'
	input_loc['Omegac'] = 'Phys/B2DMuNuX_OmegacLine/Particles'
	input_loc['Xic']    = 'Phys/B2DMuNuX_XicLine/Particles'
else:
	input_loc['Dp'] = 'Phys/b2DpMuXB2DMuNuXLine/Particles'
	input_loc['D0'] = 'Phys/b2D0MuXB2DMuNuXLine/Particles'
	input_loc['Ds'] = 'Phys/b2DsMuXB2DMuNuXLine/Particles'
	input_loc['Lc'] = 'Phys/b2LcMuXB2DMuNuXLine/Particles'

'''
# Can use this to modify the cuts applied in the stripping
config['B2DMuNuX']
{'CONFIG': {'KPiPT': 300.0, 'Dstar_SoftPion_PT': 180.0, 'PrescalDsPi_fakes': 0.5, 'MuonIPCHI2': 4.0, 'TRGHOSTPROB': 0.5, 'Dstar_SoftPion_PIDe': 2.0, 'PIDmu': -0.0, 'DZ': 0, 'TRCHI2Loose': 5.0, 'DsVCHI2DOF': 6.0, 'DZLoose': -9999, 'MINIPCHI2': 9.0, 'DsFDCHI2': 100.0, 'MuonPT': 800.0, 'Dstar_wideDMCutLower': 0.0, 'D02HHHHMassWin': 60.0, 'GEC_nLongTrk': 250, 'BVCHI2DOF': 6.0, 'DsAMassWin': 100.0, 'Dstar_wideDMCutUpper': 170.0, 'DsIP': 7.4, 'DsMassWin': 80.0, 'DDocaChi2Max': 20, 'DDocaChi2MaxTight': 9.0, 'DsDIRA': 0.99, 'MINIPCHI2Loose': 4.0, 'TRCHI2': 4.0, 'KaonPIDK': 4.0, 'PhiMassWin': 40, 'PrescalD0Mu': 0.5, 'PionPIDK': 10.0, 'PhiVCHI2': 25.0, 'MuonGHOSTPROB': 0.5, 'D02HHHHSumPT': 1800.0, 'Dstar_Chi2': 8.0, 'PionPIDKTight': 4.0, 'BDIRA': 0.999, 'KaonPIDKloose': -5, 'KaonPIDKTight': 8.0}, 'STREAMS': ['Semileptonic'], 'BUILDERTYPE': 'B2DMuNuXAllLinesConf', 'WGs': ['Semileptonic']}
'''

#########################################################################################################
### Set the event location. For MC, rerun the stripping
#########################################################################################################
if MODE == "MC":
    from StrippingConf.Configuration import StrippingConf, StrippingStream
    from StrippingSettings.Utils import strippingConfiguration
    from StrippingArchive.Utils import buildStreams
    from StrippingArchive import strippingArchive
    import shelve

    stripping = 'stripping22'
    #get the configuration dictionary from the database
    config_db = strippingConfiguration(stripping)
    config = dict(config_db) # need to do this since the config_db is read-only
    config['B2DMuNuX']['CONFIG']['UseNoPIDsInputs'] = True
    config['B2DMuNuX']['CONFIG']['MuonPIDmu'] = -1000.
    config['B2DMuNuX']['CONFIG']['ProtonPIDp'] = -1000.
    config['B2DMuNuX']['CONFIG']['ProtonPIDpK'] = -1000.
    config['B2DMuNuX']['CONFIG']['KaonPIDK'] = -1000.
    config['B2DMuNuX']['CONFIG']['PionPIDK'] = 1000.
    config['B2DMuNuX']['CONFIG']['ElectronPIDe'] = -1000.

    config_db_updated = shelve.open('tmp_stripping_config.db')
    config_db_updated.update(config)
    #get the line builders from the archive
    archive = strippingArchive(stripping)
    myWG = "Semileptonic"

    streams = buildStreams(stripping = config_db_updated, archive = archive, WGs = myWG)

    from Configurables import ProcStatusCheck
    filterBadEvents = ProcStatusCheck()

    sc = StrippingConf( Streams = streams,
                    MaxCandidates = 2000,
                    AcceptBadEvents = False,
                    BadEventSelection = filterBadEvents,
                    TESPrefix = 'Strip' )

    from Configurables import StrippingReport
    sr = StrippingReport(Selections = sc.selections())
    sr.OnlyPositive = False
    location = ''

    # Need to remove stripping banks (if stripping has previously been run)
    from Configurables import EventNodeKiller
    eventNodeKiller = EventNodeKiller('Stripkiller')
    eventNodeKiller.Nodes = [ '/Event/AllStreams', '/Event/Strip' ]

else:
    # for data
    #location='/Event/Semileptonic/'
    location='/Event/ALL/'


#########################################################################################################
# Set up the MCDecayTreeTuples for each of the decays that we are interested in.
# We want to save all of the generated events for each mode.
#########################################################################################################
from Configurables import MCDecayTreeTuple, MCTupleToolKinematic, MCTupleToolHierarchy, LoKi__Hybrid__MCTupleTool

# LoKi variables
LoKi_Photos = LoKi__Hybrid__MCTupleTool("LoKi_Photos")
LoKi_Photos.Variables = {
    "nPhotons" : "MCNINTREE ( ('gamma'==MCABSID) )",
    "MC_PT"    : "MCPT",
    "MC_THETA" : "MCTHETA",
    "MC_ETA"   : "MCETA",
    "MC_PHI"   : "MCPHI",
    "MC_ABSID" : "MCABSID"
	}

mctuple_b2D0MuX = MCDecayTreeTuple( 'MCTuple_b2D0MuX' )
mctuple_b2D0MuX.Decay = "[ (Beauty & LongLived) --> ^(D~0 -> ^K+ ^pi- ...) ^nu_mu ^mu+ ... ]CC"
mctuple_b2D0MuX.Branches = {
		'B'  : "[ (Beauty & LongLived) -->  (D~0 ->  K+  pi- ...)  nu_mu  mu+ ... ]CC",
		'D'  : "[ (Beauty & LongLived) --> ^(D~0 ->  K+  pi- ...)  nu_mu  mu+ ... ]CC",
		'K1' : "[ (Beauty & LongLived) -->  (D~0 -> ^K+  pi- ...)  nu_mu  mu+ ... ]CC",
		'pi1': "[ (Beauty & LongLived) -->  (D~0 ->  K+ ^pi- ...)  nu_mu  mu+ ... ]CC",
		'nu' : "[ (Beauty & LongLived) -->  (D~0 ->  K+  pi- ...) ^nu_mu  mu+ ... ]CC",
		'mu' : "[ (Beauty & LongLived) -->  (D~0 ->  K+  pi- ...)  nu_mu ^mu+ ... ]CC"
		}

mctuple_b2D0eX = MCDecayTreeTuple( 'MCTuple_b2D0eX' )
mctuple_b2D0eX.Decay = "[ (Beauty & LongLived) --> ^(D~0 -> ^K+ ^pi- ...) ^nu_e ^e+ ... ]CC"
mctuple_b2D0eX.Branches = {
		'B'  : "[ (Beauty & LongLived) -->  (D~0 ->  K+  pi- ...)  nu_e  e+ ... ]CC",
		'D'  : "[ (Beauty & LongLived) --> ^(D~0 ->  K+  pi- ...)  nu_e  e+ ... ]CC",
		'K1' : "[ (Beauty & LongLived) -->  (D~0 -> ^K+  pi- ...)  nu_e  e+ ... ]CC",
		'pi1': "[ (Beauty & LongLived) -->  (D~0 ->  K+ ^pi- ...)  nu_e  e+ ... ]CC",
		'nu' : "[ (Beauty & LongLived) -->  (D~0 ->  K+  pi- ...) ^nu_e  e+ ... ]CC",
		'e'  : "[ (Beauty & LongLived) -->  (D~0 ->  K+  pi- ...)  nu_e ^e+ ... ]CC"
		}

mctuple_b2DpMuX = MCDecayTreeTuple( 'MCTuple_b2DpMuX' )
mctuple_b2DpMuX.Decay = "[ (Beauty & LongLived)   --> ^(D- -> ^K+ ^pi- ^pi- ...) ^nu_mu ^mu+ ... ]CC"
mctuple_b2DpMuX.Branches = {
		"B"  : "[ (Beauty & LongLived)   -->  (D- ->  K+  pi-  pi- ...)  nu_mu  mu+ ... ]CC",
		"D"  : "[ (Beauty & LongLived)   --> ^(D- ->  K+  pi-  pi- ...)  nu_mu  mu+ ... ]CC",
		"K1" : "[ (Beauty & LongLived)   -->  (D- -> ^K+  pi-  pi- ...)  nu_mu  mu+ ... ]CC",
		"pi1": "[ (Beauty & LongLived)   -->  (D- ->  K+ ^pi-  pi- ...)  nu_mu  mu+ ... ]CC",
		"pi2": "[ (Beauty & LongLived)   -->  (D- ->  K+  pi- ^pi- ...)  nu_mu  mu+ ... ]CC",
		"nu" : "[ (Beauty & LongLived)   -->  (D- ->  K+  pi-  pi- ...) ^nu_mu  mu+ ... ]CC",
		"mu" : "[ (Beauty & LongLived)   -->  (D- ->  K+  pi-  pi- ...)  nu_mu ^mu+ ... ]CC"
		}

mctuple_b2DsMuX = MCDecayTreeTuple( 'MCTuple_b2DsMuX' )
mctuple_b2DsMuX.Decay = "[ (Beauty & LongLived) --> ^(D_s- -> ^K+ ^K- ^pi- ...) ^nu_mu ^mu+ ... ]CC"
mctuple_b2DsMuX.Branches = {
		"B"  : "[ (Beauty & LongLived) -->  (D_s- ->  K+  K-  pi- ...)  nu_mu  mu+ ... ]CC",
		"D"  : "[ (Beauty & LongLived) --> ^(D_s- ->  K+  K-  pi- ...)  nu_mu  mu+ ... ]CC",
		"K1" : "[ (Beauty & LongLived) -->  (D_s- -> ^K+  K-  pi- ...)  nu_mu  mu+ ... ]CC",
		"K2" : "[ (Beauty & LongLived) -->  (D_s- ->  K+ ^K-  pi- ...)  nu_mu  mu+ ... ]CC",
		"pi1": "[ (Beauty & LongLived) -->  (D_s- ->  K+  K- ^pi- ...)  nu_mu  mu+ ... ]CC",
		"nu" : "[ (Beauty & LongLived) -->  (D_s- ->  K+  K-  pi- ...) ^nu_mu  mu+ ... ]CC",
		"mu" : "[ (Beauty & LongLived) -->  (D_s- ->  K+  K-  pi- ...)  nu_mu ^mu+ ... ]CC"
		}

mctuple_b2LcMuX = MCDecayTreeTuple( 'MCTuple_b2LcMuX' )
# Need the --> arrow for the Lambda_b~0 decay since the .dec file for EventType 15874000 includes K*, Lambda0 and Delta's in the Lambda_b decay
mctuple_b2LcMuX.Decay = "[ (Beauty & LongLived) --> ^(Lambda_c~- --> ^p~- ^K+ ^pi- ...) ^nu_mu ^mu+ ... ]CC"
mctuple_b2LcMuX.Branches = {
		"B"  : "[ (Beauty & LongLived) -->  (Lambda_c~- -->  p~-  K+  pi- ...)  nu_mu  mu+ ... ]CC",
		"D"  : "[ (Beauty & LongLived) --> ^(Lambda_c~- -->  p~-  K+  pi- ...)  nu_mu  mu+ ... ]CC",
		"p1" : "[ (Beauty & LongLived) -->  (Lambda_c~- --> ^p~-  K+  pi- ...)  nu_mu  mu+ ... ]CC",
		"K1" : "[ (Beauty & LongLived) -->  (Lambda_c~- -->  p~- ^K+  pi- ...)  nu_mu  mu+ ... ]CC",
		"pi1": "[ (Beauty & LongLived) -->  (Lambda_c~- -->  p~-  K+ ^pi- ...)  nu_mu  mu+ ... ]CC",
		"nu" : "[ (Beauty & LongLived) -->  (Lambda_c~- -->  p~-  K+  pi- ...) ^nu_mu  mu+ ... ]CC",
		"mu" : "[ (Beauty & LongLived) -->  (Lambda_c~- -->  p~-  K+  pi- ...)  nu_mu ^mu+ ... ]CC"
		}

mctuple_b2OmegacMuX = MCDecayTreeTuple( 'MCTuple_b2OmegacMuX' )
mctuple_b2OmegacMuX.Decay = "[ (Beauty & LongLived) --> ^(Omega_c~0 -> ^p~- ^K+ ^K- ^pi- ...) ^nu_mu ^mu+ ... ]CC"
mctuple_b2OmegacMuX.Branches = {
		"B"  : "[ (Beauty & LongLived) -->  (Omega_c~0 ->  p~-  K+  K-  pi+ ...)  nu_mu  mu+ ... ]CC",
		"D"  : "[ (Beauty & LongLived) --> ^(Omega_c~0 ->  p~-  K+  K-  pi+ ...)  nu_mu  mu+ ... ]CC",
		"p1" : "[ (Beauty & LongLived) -->  (Omega_c~0 -> ^p~-  K+  K-  pi+ ...)  nu_mu  mu+ ... ]CC",
		"K1" : "[ (Beauty & LongLived) -->  (Omega_c~0 ->  p~- ^K+  K-  pi+ ...)  nu_mu  mu+ ... ]CC",
		"K2" : "[ (Beauty & LongLived) -->  (Omega_c~0 ->  p~-  K+ ^K-  pi+ ...)  nu_mu  mu+ ... ]CC",
		"pi1": "[ (Beauty & LongLived) -->  (Omega_c~0 ->  p~-  K+  K- ^pi+ ...)  nu_mu  mu+ ... ]CC",
		"nu" : "[ (Beauty & LongLived) -->  (Omega_c~0 ->  p~-  K+  K-  pi+ ...) ^nu_mu  mu+ ... ]CC",
		"mu" : "[ (Beauty & LongLived) -->  (Omega_c~0 ->  p~-  K+  K-  pi+ ...)  nu_mu ^mu+ ... ]CC"
		}

mctuple_b2XicMuX = MCDecayTreeTuple( 'MCTuple_b2XicMuX' )
mctuple_b2XicMuX.Decay = "[ (Beauty & LongLived) --> ^(Xi_c~- -> ^p~- ^K+ ^pi- ...) ^nu_mu ^mu+ ... ]CC"
mctuple_b2XicMuX.Branches = {
		"B"  : "[ (Beauty & LongLived) -->  (Xi_c~- ->  p~-  K+  pi- ...)  nu_mu  mu+ ... ]CC",
		"D"  : "[ (Beauty & LongLived) --> ^(Xi_c~- ->  p~-  K+  pi- ...)  nu_mu  mu+ ... ]CC",
		"p1" : "[ (Beauty & LongLived) -->  (Xi_c~- -> ^p~-  K+  pi- ...)  nu_mu  mu+ ... ]CC",
		"K1" : "[ (Beauty & LongLived) -->  (Xi_c~- ->  p~- ^K+  pi- ...)  nu_mu  mu+ ... ]CC",
		"pi1": "[ (Beauty & LongLived) -->  (Xi_c~- ->  p~-  K+ ^pi- ...)  nu_mu  mu+ ... ]CC",
		"nu" : "[ (Beauty & LongLived) -->  (Xi_c~- ->  p~-  K+  pi- ...) ^nu_mu  mu+ ... ]CC",
		"mu" : "[ (Beauty & LongLived) -->  (Xi_c~- ->  p~-  K+  pi- ...)  nu_mu ^mu+ ... ]CC"
		}

# List of the mc tuples
mctuples = [
	   mctuple_b2D0MuX
	 , mctuple_b2DpMuX
	 , mctuple_b2DsMuX
	 , mctuple_b2LcMuX
	 , mctuple_b2D0eX
	 , mctuple_b2OmegacMuX
	 , mctuple_b2XicMuX
	]

for tup in mctuples:
	tup.addTool(MCTupleToolKinematic())
	tup.MCTupleToolKinematic.Verbose=True
	tup.addTool(LoKi_Photos)
	if YEAR == '2015' and MODE == 'MC': # need to remove TupleToolEventInfo, otherwise causes L0 errors
	  tup.ToolList  = [ "MCTupleToolHierarchy"
			, "MCTupleToolKinematic"
			, "LoKi::Hybrid::MCTupleTool/LoKi_Photos" # doesn't work with DaVinci v36r6
			]
	if False: # not sure if we need this??
		tup.addTool(TupleToolMCTruth, name = "TruthTool")
		tup.addTool(TupleToolMCBackgroundInfo, name = "BackgroundInfo")
		tup.ToolList += ["TupleToolMCTruth/TruthTool"]
		tup.ToolList += ["TupleToolMCBackgroundInfo/BackgroundInfo"]
		tup.addTool(MCTupleToolHierarchy, name = "Hierarchy")
		tup.ToolList += ["MCTupleToolHierarchy/Hierarchy"]
		tup.TruthTool.addTool(MCTupleToolHierarchy())
		tup.TruthTool.ToolList+=["MCTupleToolHierarchy/Hierarchy"]


if OUTPUTLEVEL == DEBUG:
	from Configurables import PrintMCTree, PrintMCDecayTreeTool
	mctree = PrintMCTree("PrintTrue")
	mctree.addTool( PrintMCDecayTreeTool )
	mctree.PrintMCDecayTreeTool.Information = "Name M P Px Py Pz Pt Vx Vy Vz"
	#mctree.ParticleNames = [ "B0", "B~0", "B_s0", "B_s~0", "B+", "B-", "Lambda_b0", "Lambda_b~0" ]
	#mctree.ParticleNames = [ "B0", "B~0" ]
	#mctree.ParticleNames = [ "B_s0", "B_s~0" ]
	#mctree.ParticleNames = [ "B+", "B-" ]
	mctree.ParticleNames = [ "Lambda_b0", "Lambda_b~0" ]
	mctree.Depth = 3  # down to the K and mu

#########################################################################################################
# Now set up the DecayTreeTuples for the reconstructed particles
#########################################################################################################
tupletools = []
tupletools.append("TupleToolPrimaries")
tupletools.append("TupleToolKinematic")
tupletools.append("TupleToolGeometry")
tupletools.append("TupleToolTrackInfo")
tupletools.append("TupleToolPid")
tupletools.append("TupleToolRecoStats")
tupletools.append("TupleToolEventInfo")

triglist = ['L0MuonDecision',
            'L0HadronDecision',
            'Hlt1SingleMuonNoIPDecision',
            'Hlt1TrackMuonDecision',
            'Hlt1TrackAllL0Decision',
            'Hlt2SingleMuonDecision',
            'Hlt2TopoMu2BodyBBDTDecision',
            'Hlt2TopoMu3BodyBBDTDecision',
            'Hlt2TopoMu4BodyBBDTDecision',
            'Hlt2Topo2BodyBBDTDecision',
            'Hlt2Topo3BodyBBDTDecision',
            'Hlt2Topo4BodyBBDTDecision'
	]
TISTOSTool = TupleToolTISTOS('TISTOSTool')
TISTOSTool.VerboseL0   = True
TISTOSTool.VerboseHlt1 = True
TISTOSTool.VerboseHlt2 = True
TISTOSTool.TriggerList = triglist[:]
TISTOSTool.addTool( TriggerTisTos, name="TriggerTisTos")
TISTOSTool.TriggerTisTos.TOSFracEcal = 0.
TISTOSTool.TriggerTisTos.TOSFracHcal = 0.

#### Get the corrected mass for the B
LoKi_B = LoKi__Hybrid__TupleTool("LoKi_B")
LoKi_B.Variables =  {
        "Best_PV_CORRM" : "BPVCORRM",
        "Best_PV_Eta"   : "BPVETA",
        "ETA" : "ETA",
        "PHI" : "PHI"
}

LoKi_Mu = LoKi__Hybrid__TupleTool("LoKi_Mu")
LoKi_Mu.Variables =  {
    "NSHAREDMU" : "NSHAREDMU"
    }

tuple_b2DpMuX = DecayTreeTuple("Tuple_b2DpMuX")
tuple_b2DpMuX.Inputs = [ location + input_loc['Dp'] ]
tuple_b2DpMuX.ToolList = tupletools[:]
tuple_b2DpMuX.Decay = '[B0 -> ^(D- -> ^K+ ^pi- ^pi-) ^mu+]CC'
tuple_b2DpMuX.Branches = {
        "B"   : "[B0 ->  ( D- ->  K+  pi-  pi-)  mu+]CC",
        "D"   : "[B0 -> ^( D- ->  K+  pi-  pi-)  mu+]CC",
        "mu"  : "[B0 ->  ( D- ->  K+  pi-  pi-) ^mu+]CC",
        "K1"  : "[B0 ->  ( D- -> ^K+  pi-  pi-)  mu+]CC",
        "pi1" : "[B0 ->  ( D- ->  K+ ^pi-  pi-)  mu+]CC",
        "pi2" : "[B0 ->  ( D- ->  K+  pi- ^pi-)  mu+]CC"
	}
for particle in ["B","D","mu","K1","pi1","pi2"]:
        tuple_b2DpMuX.addTool(TupleToolDecay, name = particle)

tuple_b2D0MuX = DecayTreeTuple("Tuple_b2D0MuX")
tuple_b2D0MuX.Inputs = [ location + input_loc['D0'] ]
tuple_b2D0MuX.ToolList = tupletools[:]
tuple_b2D0MuX.Decay = '[B+ -> ^(D~0 -> ^K+ ^pi-) ^mu+]CC'
tuple_b2D0MuX.Branches = {
        "B"   : "[B+ ->  ( D~0 ->   K+   pi-)   mu+]CC",
        "D"   : "[B+ -> ^( D~0 ->   K+   pi-)   mu+]CC",
        "mu"  : "[B+ ->  ( D~0 ->   K+   pi-)  ^mu+]CC",
        "K1"  : "[B+ ->  ( D~0 ->  ^K+   pi-)   mu+]CC",
        "pi1" : "[B+ ->  ( D~0 ->   K+  ^pi-)   mu+]CC",
	}
for particle in ["B","D","mu","K1","pi1"]:
        tuple_b2D0MuX.addTool(TupleToolDecay, name = particle)

tuple_b2D0eX = DecayTreeTuple("Tuple_b2D0eX")
tuple_b2D0eX.Inputs = [ location + input_loc['D0e'] ]
tuple_b2D0eX.ToolList = tupletools[:]
tuple_b2D0eX.Decay = '[B+ -> ^(D~0 -> ^K+ ^pi-) ^e+]CC'
tuple_b2D0eX.Branches = {
        "B"   : "[B+ ->  ( D~0 ->   K+   pi-)   e+]CC",
        "D"   : "[B+ -> ^( D~0 ->   K+   pi-)   e+]CC",
        "mu"  : "[B+ ->  ( D~0 ->   K+   pi-)  ^e+]CC",
        "K1"  : "[B+ ->  ( D~0 ->  ^K+   pi-)   e+]CC",
        "pi1" : "[B+ ->  ( D~0 ->   K+  ^pi-)   e+]CC",
	}
for particle in ["B","D","mu","K1","pi1"]:
        tuple_b2D0eX.addTool(TupleToolDecay, name = particle)

# For the B_s0, Ds: the stripping is defined such that a B0 and D- is reconstructed
tuple_b2DsMuX = DecayTreeTuple("Tuple_b2DsMuX")
tuple_b2DsMuX.Inputs = [ location + input_loc['Ds'] ]
tuple_b2DsMuX.ToolList = tupletools[:]
tuple_b2DsMuX.Decay = '[B0 -> ^(D- -> ^K+ ^K- ^pi-) ^mu+]CC'
tuple_b2DsMuX.Branches = {
        "B"   : "[B0 ->  ( D- ->  K+  K-  pi-)  mu+]CC",
        "D"   : "[B0 -> ^( D- ->  K+  K-  pi-)  mu+]CC",
        "mu"  : "[B0 ->  ( D- ->  K+  K-  pi-) ^mu+]CC",
        "K1"  : "[B0 ->  ( D- -> ^K+  K-  pi-)  mu+]CC",
        "K2"  : "[B0 ->  ( D- ->  K+ ^K-  pi-)  mu+]CC",
        "pi1" : "[B0 ->  ( D- ->  K+  K- ^pi-)  mu+]CC"
	}
for particle in ["B","D","mu","K1","K2","pi1"]:
        tuple_b2DsMuX.addTool(TupleToolDecay, name = particle)

from Configurables import PrintDecayTree
printTree = PrintDecayTree("printTree")
printTree.Inputs = [ location + input_loc['Ds']]

tuple_b2LcMuX = DecayTreeTuple("Tuple_b2LcMuX")
tuple_b2LcMuX.Inputs = [ location + input_loc['Lc'] ]
tuple_b2LcMuX.ToolList = tupletools[:]
tuple_b2LcMuX.Decay = '[Lambda_b~0 -> ^(Lambda_c~- -> ^p~- ^K+ ^pi-) ^mu+]CC'
tuple_b2LcMuX.Branches = {
        "B"   : "[Lambda_b~0 ->  ( Lambda_c~- ->  p~-  K+  pi-)  mu+]CC",
        "D"   : "[Lambda_b~0 -> ^( Lambda_c~- ->  p~-  K+  pi-)  mu+]CC",
        "mu"  : "[Lambda_b~0 ->  ( Lambda_c~- ->  p~-  K+  pi-) ^mu+]CC",
        "p1"  : "[Lambda_b~0 ->  ( Lambda_c~- -> ^p~-  K+  pi-)  mu+]CC",
        "K1"  : "[Lambda_b~0 ->  ( Lambda_c~- ->  p~- ^K+  pi-)  mu+]CC",
        "pi1" : "[Lambda_b~0 ->  ( Lambda_c~- ->  p~-  K+ ^pi-)  mu+]CC"
	}
for particle in ["B","D","mu","p1","K1","pi1"]:
        tuple_b2LcMuX.addTool(TupleToolDecay, name = particle)

tuple_b2OmegacMuX = DecayTreeTuple("Tuple_b2OmegacMuX")
tuple_b2OmegacMuX.Inputs = [ location + input_loc['Omegac'] ]
tuple_b2OmegacMuX.ToolList = tupletools[:]
tuple_b2OmegacMuX.Decay = '[Omega_b~+ -> ^(Lambda_c~- -> ^p~- ^K+ ^K- ^pi+) ^mu+]CC'
tuple_b2OmegacMuX.Branches = {
        "B"   : "[Omega_b~+ ->  ( Omega_c~0 ->  p~-  K+  K-  pi+)  mu+]CC",
        "D"   : "[Omega_b~+ -> ^( Omega_c~0 ->  p~-  K+  K-  pi+)  mu+]CC",
        "mu"  : "[Omega_b~+ ->  ( Omega_c~0 ->  p~-  K+  K-  pi+) ^mu+]CC",
        "p1"  : "[Omega_b~+ ->  ( Omega_c~0 -> ^p~-  K+  K-  pi+)  mu+]CC",
        "K1"  : "[Omega_b~+ ->  ( Omega_c~0 ->  p~- ^K+  K-  pi+)  mu+]CC",
        "K2"  : "[Omega_b~+ ->  ( Omega_c~0 ->  p~-  K+ ^K-  pi+)  mu+]CC",
        "pi1" : "[Omega_b~+ ->  ( Omega_c~0 ->  p~-  K+  K- ^pi+)  mu+]CC"
	}
for particle in ["B","D","mu","p1","K1","K2", "pi1"]:
        tuple_b2OmegacMuX.addTool(TupleToolDecay, name = particle)

tuple_b2XicMuX = DecayTreeTuple("Tuple_b2XicMuX")
tuple_b2XicMuX.Inputs = [ location + input_loc['Xic'] ]
tuple_b2XicMuX.ToolList = tupletools[:]
tuple_b2XicMuX.Decay = '[Xi_b~0 -> ^(Xi_c~- -> ^p~- ^K+ ^pi-) ^mu+]CC'
tuple_b2XicMuX.Branches = {
        "B"   : "[Xi_b~0 ->  ( Xi_c~- ->  p~-  K+  pi-)  mu+]CC",
        "D"   : "[Xi_b~0 -> ^( Xi_c~- ->  p~-  K+  pi-)  mu+]CC",
        "mu"  : "[Xi_b~0 ->  ( Xi_c~- ->  p~-  K+  pi-) ^mu+]CC",
        "p1"  : "[Xi_b~0 ->  ( Xi_c~- -> ^p~-  K+  pi-)  mu+]CC",
        "K1"  : "[Xi_b~0 ->  ( Xi_c~- ->  p~- ^K+  pi-)  mu+]CC",
        "pi1" : "[Xi_b~0 ->  ( Xi_c~- ->  p~-  K+ ^pi-)  mu+]CC"
	}
for particle in ["B","D","mu","p1","K1","pi1"]:
        tuple_b2XicMuX.addTool(TupleToolDecay, name = particle)

# List of the reconstructed tuples
tuples = [ tuple_b2D0MuX
	 , tuple_b2DpMuX
	 , tuple_b2DsMuX
	 , tuple_b2LcMuX
	 , tuple_b2D0eX
	 , tuple_b2OmegacMuX
	 , tuple_b2XicMuX
	]

for tup in tuples:
    tup.ReFitPVs = True
    if MODE == "MC":
        tup.addTool(TupleToolMCTruth, name = "TruthTool")
        tup.addTool(TupleToolMCBackgroundInfo, name = "BackgroundInfo")
        tup.ToolList += ["TupleToolMCTruth/TruthTool"]
        tup.ToolList += ["TupleToolMCBackgroundInfo/BackgroundInfo"]

    tup.B.addTool( LoKi_B )
    tup.B.ToolList += ["LoKi::Hybrid::TupleTool/LoKi_B"]
    tup.mu.addTool( LoKi_Mu )
    tup.mu.ToolList += ["LoKi::Hybrid::TupleTool/LoKi_Mu"]
    #if YEAR != '2015':
    for particle in [ tup.B, tup.mu ]:
        particle.addTool(TISTOSTool, name = "TISTOSTool")
        particle.ToolList += [ "TupleToolTISTOS/TISTOSTool" ]

##################################################################
# If we want to write a DST do this
##################################################################
from DSTWriters.microdstelements import *
from DSTWriters.Configuration import (SelDSTWriter,
                                              stripDSTStreamConf,
                                              stripDSTElements
                                              )
SelDSTWriterElements = {
    'default'              : stripDSTElements()
    }
SelDSTWriterConf = {
    'default'              : stripDSTStreamConf()
    }
if MODE == 'MC':
  dstWriter = SelDSTWriter( "MyDSTWriter",
                          StreamConf = SelDSTWriterConf,
                          MicroDSTElements = SelDSTWriterElements,
                          OutputFileSuffix ='MC',
                          SelectionSequences = sc.activeStreams()
                          )

###################### DAVINCI SETTINGS ############################################

DaVinci().SkipEvents = 0  #1945
DaVinci().PrintFreq = 1000
DaVinci().EvtMax = EVTMAX
DaVinci().TupleFile = "DVTuples1noGEC.root"
DaVinci().HistogramFile = 'DVHistos.root'
DaVinci().InputType = "DST"
DaVinci().Simulation = False
DaVinci().Lumi = True
DaVinci().DataType = "2015"
if MODE == "2012":
    DaVinci().DataType = "2012"
if MODE != "MC":
    DaVinci().DDDBtag  = "dddb-20150526"
    DaVinci().CondDBtag = "cond-20150602"
if MODE == "MC":
	DaVinci().Simulation = True
	DaVinci().Lumi = False
	DaVinci().appendToMainSequence([eventNodeKiller])
	DaVinci().appendToMainSequence([sc.sequence()])
	DaVinci().appendToMainSequence([sr])

if False: # Add the DST writing algorithms
	DaVinci().appendToMainSequence( [ dstWriter.sequence(), printTree ] )

if True: # Add the ntuple writing algorithms
	DaVinci().UserAlgorithms = [
			     tuple_b2D0MuX
			   , tuple_b2DpMuX
			   , tuple_b2DsMuX
			   , tuple_b2LcMuX
			   , tuple_b2D0eX
			   , tuple_b2OmegacMuX
			   , tuple_b2XicMuX
			]
	if MODE == 'MC':
		DaVinci().UserAlgorithms += [
			     mctuple_b2D0MuX
			   , mctuple_b2DsMuX
			   , mctuple_b2LcMuX
			   , mctuple_b2DpMuX
			   , mctuple_b2D0eX
			   , mctuple_b2OmegacMuX
			   , mctuple_b2XicMuX
			]
if OUTPUTLEVEL == DEBUG:
	DaVinci().MoniSequence += [ mctree ]

from Configurables import  DaVinciInit
DaVinciInit().OutputLevel = OUTPUTLEVEL

if MODE != "MC":
    from Configurables import LumiIntegrateFSR, LumiIntegratorConf
    LumiIntegrateFSR('IntegrateBeamCrossing').SubtractBXTypes = ['None']

MessageSvc().Format = "% F%60W%S%7W%R%T %0W%M"

###################################################################################
####################### THE END ###################################################
###################################################################################
