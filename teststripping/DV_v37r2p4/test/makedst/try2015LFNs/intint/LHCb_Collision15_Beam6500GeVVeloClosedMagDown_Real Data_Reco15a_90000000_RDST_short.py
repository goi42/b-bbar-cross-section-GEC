#-- GAUDI jobOptions generated on Fri Dec 11 17:50:14 2015
#-- Contains event types : 
#--   90000000 - 159841 files - 8650720162 events - 338002.73 GBytes


#--  Extra information about the data processing phases:


#--  Processing Pass Step-127957 

#--  StepId : 127957 
#--  StepName : DataQuality-FULL-2015-FirstDataType2015-RDST 
#--  ApplicationName : DaVinci 
#--  ApplicationVersion : v36r7p1 
#--  OptionFiles : $APPCONFIGOPTS/DaVinci/DVMonitor-RealData.py;$APPCONFIGOPTS/DaVinci/DataType-2015.py;$APPCONFIGOPTS/DaVinci/DaVinci-InputType-SDST.py 
#--  DDDB : fromPreviousStep 
#--  CONDDB : fromPreviousStep 
#--  ExtraPackages : AppConfig.v3r214;SQLDDDB.v7r10 
#--  Visible : N 


#--  Processing Pass Step-128577 

#--  StepId : 128577 
#--  StepName : FULL-Reco15a-cond-20150828-RDST 
#--  ApplicationName : Brunel 
#--  ApplicationVersion : v48r2 
#--  OptionFiles : $APPCONFIGOPTS/Brunel/DataType-2015.py;$APPCONFIGOPTS/Brunel/rdst.py 
#--  DDDB : dddb-20150724 
#--  CONDDB : cond-20150828 
#--  ExtraPackages : AppConfig.v3r235;SQLDDDB.v7r10 
#--  Visible : Y 

from Gaudi.Configuration import * 
from GaudiConf import IOHelper
IOHelper('ROOT').inputFiles(['LFN:/lhcb/LHCb/Collision15/RDST/00048237/0000/00048237_00000001_1.rdst',
'LFN:/lhcb/LHCb/Collision15/RDST/00048237/0000/00048237_00000002_1.rdst',
'LFN:/lhcb/LHCb/Collision15/RDST/00048237/0000/00048237_00000003_1.rdst',
'LFN:/lhcb/LHCb/Collision15/RDST/00048237/0000/00048237_00000004_1.rdst',
'LFN:/lhcb/LHCb/Collision15/RDST/00048237/0000/00048237_00000005_1.rdst',
'LFN:/lhcb/LHCb/Collision15/RDST/00048237/0000/00048237_00000006_1.rdst',
'LFN:/lhcb/LHCb/Collision15/RDST/00048237/0000/00048237_00000007_1.rdst',
'LFN:/lhcb/LHCb/Collision15/RDST/00048237/0000/00048237_00000008_1.rdst',
'LFN:/lhcb/LHCb/Collision15/RDST/00048237/0000/00048237_00000009_1.rdst',
'LFN:/lhcb/LHCb/Collision15/RDST/00048237/0000/00048237_00000010_1.rdst',
'LFN:/lhcb/LHCb/Collision15/RDST/00048237/0000/00048237_00000011_1.rdst',
], clear=True)
FileCatalog().Catalogs += [ 'xmlcatalog_file:pool_xml_catalog.xml' ]
