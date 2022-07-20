import java.util.Scanner;
import java.util.ArrayList;

public class Question2 {
    public static boolean doesIDExist(String id, ArrayList<ProjMember> projMembers) {
        Boolean response = false;
        for (int i = 0; i < projMembers.size(); i++) {
            if (id.equals(projMembers.get(i).getId()))
                response = true;
        }
        return response;
    }

    public static boolean doesTeamNameExist(String teamName, ArrayList<ProjTeam> projTeam) {
        Boolean response = false;
        for (int i = 0; i < projTeam.size(); i++) {
            if (teamName.equals(projTeam.get(i).getTeamName()))
                return true;
        }
        return response;
    }

    public static void main(String[] args) {
        ArrayList<ProjTeam> projTeamList = new ArrayList<ProjTeam>();
        ArrayList<ProjMember> projMemberList = new ArrayList<ProjMember>();

        Scanner input = new Scanner(System.in);
        boolean run = true;

        while (run) {
            System.out.println("1 Add member");
            System.out.println("2 Remove member");
            System.out.println("3 Add project team");
            System.out.println("4 Add member to project team");
            System.out.println("5 Remove member from project team");
            System.out.println("6 Print all teams");
            System.out.println("7 Quit");
            System.out.println("Your selection:");

            String response = input.nextLine();
            switch (response) {
                case "1":
                    System.out.println("Enter the new member's ID");
                    String newID = input.nextLine();
                    System.out.println("Enter the new member's Name");
                    String newName = input.nextLine();
                    System.out.println("Enter the new member's Email");
                    String newEmail = input.nextLine();

                    if (projMemberList.size() == 0) {
                        ProjMember member = new ProjMember(newID, newName, newEmail);

                        projMemberList.add(member);

                        System.out.println(member.toString() + " has been registed successfully");
                    } else {
                        for (int i = 0; i < projMemberList.size(); i++) {
                            if (newID.equals(projMemberList.get(i).getId())
                                    && newEmail.equals(projMemberList.get(i).getEmail())) {
                                System.out.println("This member is already registed in the project member's list");
                            } else {
                                ProjMember member = new ProjMember(newID, newName, newEmail);

                                projMemberList.add(member);

                                System.out.println(member.toString() + " has been registed successfully");
                            }
                        }
                    }

                    break;
                case "2":
                    System.out.println("Enter the member's ID that you want to remove");
                    String IDtoRemove = input.nextLine();

                    if (doesIDExist(IDtoRemove, projMemberList)) {
                        if (projMemberList.size() == 0)
                            System.out.println("This member does not exist in the project member's list");

                        for (int i = 0; i < projTeamList.size(); i++) {
                            if (doesIDExist(IDtoRemove, projTeamList.get(i).getProjMembers()))
                                System.out.println("This member is still part of a project team");
                            else {
                                for (int a = 0; a < projMemberList.size(); a++) {
                                    if (IDtoRemove.equals(projMemberList.get(a).getId()))
                                        projMemberList.remove(a);
                                    System.out.println(
                                            "This member has been successfully removed from the project member's list");

                                }
                            }
                        }
                    } else
                        System.out.println("This member does not exist in the project member's list");

                    break;
                case "3":
                    System.out.println("Enter the new project team's name");
                    String newTeamName = input.nextLine();

                    if (projTeamList.size() == 0) {
                        ProjTeam projTeam = new ProjTeam(newTeamName);

                        projTeamList.add(projTeam);

                        System.out.println(newTeamName + " has been successfully added to the project team list");
                    } else {
                        for (int i = 0; i < projTeamList.size(); i++) {
                            if (doesTeamNameExist(newTeamName, projTeamList))
                                System.out.println("This project team name already exists");
                            else {
                                ProjTeam projTeam = new ProjTeam(newTeamName);

                                projTeamList.add(projTeam);

                                System.out
                                        .println(newTeamName + " has been successfully added to the project team list");
                            }
                        }
                    }
                    break;
                case "4":
                    System.out.println("Enter the project team's name");
                    String addingTeamName = input.nextLine();
                    System.out.println("Enter the member's ID that you want to add");
                    String addingMemberId = input.nextLine();

                    Boolean doesExist = false;

                    if (!doesTeamNameExist(addingTeamName, projTeamList)) {
                        System.out.println("This project team name does not exist");
                        doesExist = true;
                    }

                    if (!doesIDExist(addingMemberId, projMemberList)) {

                        System.out.println("This member is not registed in the project member's list");
                        doesExist = true;
                    }

                    if (!doesExist) {
                        for (int a = 0; a < projTeamList.size(); a++) {
                            if (addingTeamName.equals(projTeamList.get(a).getTeamName())) {
                                ArrayList<ProjMember> currentProjMembers = new ArrayList<ProjMember>();
                                if (projTeamList.get(a).getProjMembers() != null) {
                                    currentProjMembers = projTeamList.get(a).getProjMembers();
                                }
                                for (int b = 0; b < projMemberList.size(); b++) {
                                    if (addingMemberId.equals(projMemberList.get(b).getId())) {
                                        currentProjMembers.add(projMemberList.get(b));
                                    }
                                }

                                projTeamList.get(a).setProjMembers(currentProjMembers);
                                System.out.println("The member's list for project team name "
                                        + projTeamList.get(a).getTeamName() + " has been updated");

                            }
                        }
                    }

                    break;
                case "5":
                    System.out.println("Enter the project team's name");
                    String teamNameToRemove = input.nextLine();
                    System.out.println("Enter the member's ID that you want to remove");
                    String memberIDToRemove = input.nextLine();

                    doesExist = true;

                    if (!doesTeamNameExist(teamNameToRemove, projTeamList)) {
                        System.out.println("This project team name does not exist");
                        doesExist = false;
                    }

                    if (!doesIDExist(memberIDToRemove, projMemberList)) {
                        System.out.println("This member is not registed in the project member's list");
                        doesExist = false;
                    }

                    if (doesExist) {
                        for (int a = 0; a < projTeamList.size(); a++) {
                            if (teamNameToRemove.equals(projTeamList.get(a).getTeamName())) {
                                ArrayList<ProjMember> currentProjMembers = new ArrayList<ProjMember>();
                                if (projTeamList.get(a).getProjMembers() != null) {
                                    currentProjMembers = projTeamList.get(a).getProjMembers();
                                }
                                for (int b = 0; b < projMemberList.size(); b++) {
                                    if (memberIDToRemove.equals(projMemberList.get(b).getId())) {
                                        currentProjMembers.remove(projMemberList.get(b));
                                    }
                                }

                                projTeamList.get(a).setProjMembers(currentProjMembers);
                            }
                        }
                    }

                    break;
                case "6":
                    for (int a = 0; a < projTeamList.size(); a++) {
                        System.out.println(projTeamList.get(a));
                    }

                    break;
                default:
                    run = false;
                    break;
            }
        }
    }

}

class ProjMember {
    private String id, name, email;

    public ProjMember(String id, String name, String email) {
        this.id = id;
        this.name = name;
        this.email = email;
    }

    String getId() {
        return this.id;
    }

    String getName() {
        return this.name;
    }

    String getEmail() {
        return this.email;
    }

    void setId(String id) {
        this.id = id;
    }

    void setName(String name) {
        this.name = name;
    }

    void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "ID: " + this.getId() + " Name: " + this.getName() + " Email: " + this.getEmail();
    }
}

class ProjTeam {
    private String teamName;
    private ArrayList<ProjMember> projMembers;

    public ProjTeam(String teamName) {
        this.teamName = teamName;
    }

    String getTeamName() {
        return this.teamName;
    }

    ArrayList<ProjMember> getProjMembers() {
        return this.projMembers;
    }

    void setTeamName(String teamName) {
        this.teamName = teamName;
    }

    void setProjMembers(ArrayList<ProjMember> projMembers) {
        this.projMembers = projMembers;
    }

    @Override
    public String toString() {
        String returnString = "";
        for (int i = 0; i < this.projMembers.size(); i++) {
            returnString += "ID: " + this.projMembers.get(i).getId() + " Name: " + this.projMembers.get(i).getName()
                    + " Email: "
                    + this.projMembers.get(i).getEmail() + "\n";
        }

        return returnString;
    }
}