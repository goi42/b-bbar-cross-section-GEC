import os #use this file for everything

#myApplication = DaVinci(version='v37r2p4')
#myApplication.user_release_area = '~/cmtuser'
myApplication = DaVinci()
myApplication.user_release_area = '~/cmtuser'
myApplication.version = 'v37r2p4'
myApplication.optsfile = [File('./TestMyStrippingLineAndCreateNtuple.py')]

j = Job(name='noGEC_2015DST', application=myApplication, backend=Dirac())
j.comment = 'uses a BK query to pick up '
j.splitter = SplitByFiles(filesPerJob=5)
j.do_auto_resubmit = True
j.outputfiles = [DiracFile('*.root')] #has to match what's in opts file

BK_locations = [
    'LHCb/Collision15/Beam6500GeV-VeloClosed-MagDown/Real Data/Reco15a/Stripping23r1/90000000/SEMILEPTONIC.DST',
    'LHCb/Collision15/Beam6500GeV-VeloClosed-MagUp/Real Data/Reco15a/Stripping23r1/90000000/SEMILEPTONIC.DST'
    ]
data = LHCbDataset()
bk = BKQuery()
for path in BK_locations:
    bk.path = path
    tmp = bk.getDataset()
    if len(tmp.files) > 0:
        data.extend( tmp )

import sys
if len(data.files) < 1:
    sys.exit()

j.inputdata = data

j.submit()