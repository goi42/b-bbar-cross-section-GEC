# $Id: $
# Test your line(s) of the stripping
#  
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

from Gaudi.Configuration import *
from Configurables import DaVinci
from StrippingConf.Configuration import StrippingConf

#
#Raw event juggler to split Other/RawEvent into Velo/RawEvent and Tracker/RawEvent
#
from Configurables import RawEventJuggler
juggler = RawEventJuggler( DataOnDemand=True, Input=0.3, Output=4.2 )

#
#Fix for TrackEff lines
#
from Configurables import DecodeRawEvent
DecodeRawEvent().setProp("OverrideInputs",4.2)

# Specify the name of your configuration
confname='B2DMuNuX' #FOR USERS

# NOTE: this will work only if you inserted correctly the 
# default_config dictionary in the code where your LineBuilder 
# is defined.
from StrippingSelections import buildersConf
confs = buildersConf()
from StrippingSelections.Utils import lineBuilder, buildStreamsFromBuilder
#confs[confname]["CONFIG"]["SigmaPPi0CalPrescale"] = 0.5 ## FOR USERS, YOU ONLY NEED TO QUICKLY MODIFY CutName and NewValue (no need to recompile the package but please update the default_config before committing)
streams = buildStreamsFromBuilder(confs,confname)

#clone lines for CommonParticles overhead-free timing
#print "Creating line clones for timing"
#for s in streams:
#    for l in s.lines:
#        if "_TIMING" not in l.name():
#            cloned = l.clone(l.name().strip("Stripping")+"_TIMING")
#            s.appendLines([cloned])

#define stream names
dstStreams  = [ "Semileptonic" ]

stripTESPrefix = 'Strip'

from Configurables import ProcStatusCheck

sc = StrippingConf( Streams = streams,
                    MaxCandidates = 2000,
                    AcceptBadEvents = False,
                    BadEventSelection = ProcStatusCheck(),
                    TESPrefix = stripTESPrefix,
                    #ActiveMDSTStream = True,
                    Verbose = True,
                    DSTStreams = dstStreams)

#shows output location of all lines
lines = sc.activeLines()
for line in lines:
    print line.outputLocation()

#
# Configure the dst writers for the output
#

#Configure DaVinci
#

# Change the column size of Timing table
#from Configurables import TimingAuditor, SequencerTimerTool
#TimingAuditor().addTool(SequencerTimerTool,name="TIMER")
#TimingAuditor().TIMER.NameSize = 60

#from Configurables import AuditorSvc, ChronoAuditor
#AuditorSvc().Auditors.append( ChronoAuditor("Chrono") )

from Configurables import StrippingReport
sr = StrippingReport(Selections = sc.selections())

#from Configurables import AlgorithmCorrelationsAlg
#ac = AlgorithmCorrelationsAlg(Algorithms = list(set(sc.selections())))

#select stripping lines
input_loc = {}
input_loc['Dp']     = 'Phys/B2DMuNuX_Dp/Particles'
input_loc['D0']     = 'Phys/B2DMuNuX_D0/Particles'
input_loc['Ds']     = 'Phys/B2DMuNuX_Ds/Particles'
input_loc['Lc']     = 'Phys/B2DMuNuX_Lc/Particles'
input_loc['D0e']    = 'Phys/B2DMuNuX_D0e/Particles'
input_loc['Omegac'] = 'Phys/B2DMuNuX_Omegac/Particles'
input_loc['Xic']    = 'Phys/B2DMuNuX_Xic/Particles'

#location='/Event/Semileptonic/'
location=''

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
    tup.B.addTool( LoKi_B )
    tup.B.ToolList += ["LoKi::Hybrid::TupleTool/LoKi_B"]
    tup.mu.addTool( LoKi_Mu )
    tup.mu.ToolList += ["LoKi::Hybrid::TupleTool/LoKi_Mu"]
    #if YEAR != '2015':
    for particle in [ tup.B, tup.mu ]:
        particle.addTool(TISTOSTool, name = "TISTOSTool")
        particle.ToolList += [ "TupleToolTISTOS/TISTOSTool" ]


#Configure DaVinci

DaVinci().HistogramFile = 'DV_stripping_histos.root'
DaVinci().TupleFile = "DVTuplesTestMy.root"
DaVinci().EvtMax = -1
DaVinci().PrintFreq = 2000
DaVinci().appendToMainSequence( [ sc.sequence() ] )
DaVinci().appendToMainSequence( [ sr ] )
#DaVinci().appendToMainSequence( [ ac ] )
DaVinci().ProductionType = "Stripping"
DaVinci().DataType  = "2015"
DaVinci().InputType = "RDST"
DaVinci().Simulation = False
DaVinci().Lumi = True

# change the column size of timing table
from Configurables import TimingAuditor, SequencerTimerTool
TimingAuditor().addTool(SequencerTimerTool,name="TIMER")
TimingAuditor().TIMER.NameSize = 60

MessageSvc().Format = "% F%60W%S%7W%R%T %0W%M"

# database
DaVinci().DDDBtag   = "dddb-20150724"
DaVinci().CondDBtag = "cond-20150828"

DaVinci().UserAlgorithms = [
			     tuple_b2D0MuX
			   , tuple_b2DpMuX
			   , tuple_b2DsMuX
			   , tuple_b2LcMuX
			   , tuple_b2D0eX
			   , tuple_b2OmegacMuX
			   , tuple_b2XicMuX
			]

# input file
#importOptions("164668_Real Data_Reco15a_90000000_RDST.py")
# from Gaudi.Configuration import *
# from GaudiConf import IOHelper
# IOHelper('ROOT').inputFiles(['00048237_00008700_1.rdst'], clear=True)
# FileCatalog().Catalogs += [ 'xmlcatalog_file:$STRIPPINGSELECTIONSROOT/tests/data/Reco15a_Run164668.xml' ]
