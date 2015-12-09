import os, sys
#jid = sys.argv[1]
j = jobs(300)

for sj in j.subjobs:
   if sj.status != 'completed': continue
   for f in sj.outputfiles.get(DiracFile):
      #if (sj.id == 21 or sj.id == 57 or sj.id == 61 or sj.id == 48 or sj.id ==386):
         base_path = '/tmp/mwilkins/'
         os.makedirs(os.path.join(base_path, sj.fqid))
         f.localDir = os.path.join(base_path, sj.fqid)
         f.get()       
