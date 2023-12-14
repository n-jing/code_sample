from pyfbsdk import *

file_name = r"C:\Users\jing.jiang\Desktop\AS_PLY_F_Standard_Rifle_Strafe_Run.fbx"
FBApplication().FileOpen(file_name)


def GetGroupedObjects(groupName=str):
    ##This will unselect all objects within your scene
    for comp in FBSystem().Scene.Components:
        comp.Selected = False
    ##This will select only the objects that are in the desired group    
    for group in FBSystem().Scene.Groups:
        if groupName == group.Name:
            group.Selected = True
            for n in range(group.GetSrcCount()):
                group.GetSrc(n).Selected = True

            
##Replace "MyGroup" with the name of the group that has the objects you want selected
GetGroupedObjects("PLY_F_Bone")

def BooExPlotSelectProp():
    ExListSystem = FBSystem()
    #--------- get name of take’s
    ExListTakeNames = ExListSystem.Takes
    #print ExListTakeNames[0].Name
    #--------- get name of actor’s name
    ExListActorNames = ExListSystem.Scene.Actors
    #print ExListActorNames[0].Name
    #--------- get name of characters
    ExListCharacters = ExListSystem.Scene.Characters
    #print ExListCharacters[0].Name
    for i in range (0,len(ExListSystem.Scene.Takes),1):
        ExListTakeNames[i].PlotTakeOnSelected(FBTime(0,0,0,1))
        ExListSystem.CurrentTake = ExListSystem.Scene.Takes[i]

        
BooExPlotSelectProp()
