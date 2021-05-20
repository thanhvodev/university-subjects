/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package insert_update_delete;

/**
 *
 * @author PC
 */
class Group {
    private final String GroupID, GroupName, GroupDescription, CreatDate;
    
    Group(String id, String groupName, String groupDescription, String date) {
        GroupID = id;
        GroupName = groupName;
        GroupDescription = groupDescription;
        CreatDate = date;
    }
    
    String getGroupName() { return GroupName; }
    String getGroupID() { return GroupID; }
    String getCreatDate() { return CreatDate; }
    String getGroupDescription() { return GroupDescription; }
}
