import maya.cmds as cmds
import os, sys

cmds.scriptEditorInfo(suppressErrors=True)
cmds.scriptEditorInfo(suppressWarnings=True)
cmds.scriptEditorInfo(suppressInfo=True)


def findAllFile(base):
    for root, dirs, fs in os.walk(base):
        while len(dirs) > 0:  
            dirs.pop()  
        for f in fs:
            if f.endswith('.fbx'):
                fullname = os.path.join(root, f)
                yield fullname

fbx_dir = r'C:\Users\jing.jiang\Desktop'
json_dir = r"C:\Users\jing.jiang\Desktop\bone.json"

with open(json_dir, 'w') as outfile:
    outfile.write("{\n")
    print "open json success"
    for fbx_file in findAllFile(fbx_dir):
        print(fbx_file.replace("\\", "/"))
        fbx_name = os.path.basename(fbx_file)
        outfile.write("\t\""+fbx_name + "\":{\n")
        cmds.file(fbx_file, i=True)

        animCurves = cmds.ls(type='animCurve')
        first = cmds.findKeyframe(animCurves, which='first')
        last = cmds.findKeyframe(animCurves, which='last')
        print first
        print last
        outfile.write("\t\t\"fbxIn\":"+str(first)+",\n")
        outfile.write("\t\t\"fbxOut\":"+str(last)+",\n")
        outfile.write("\t\t\"fbxShouldIn\":"+str(first)+",\n")
        outfile.write("\t\t\"fbxShouldOut\":"+str(last)+"\n")
        outfile.write("\t},\n")
        cmds.file( f=True, new=True )        

    outfile.seek(-2, os.SEEK_END)
    outfile.truncate()
    outfile.write("\n}\n")
