package View;
import Model.Model;
import Model.MVP;
import java.util.ArrayList;
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */


/**The view class is responsible for the appearance of the interface and the presentation of data to the user. Displays data received from the model.
 * 
 * @author User Jakub Kos
 */
public class View {

   
    /**
     * 
     * Displays the result to the user, consisting of the parameters previously entered by the user.
     * 
     * @param firstTeamName First team name to display.
     * @param secondTeamName The name of the second team to display,
     * @param firstTeamScore Number of rounds won by the first team.
     * @param secondTeamScore Number of rounds won by the second team.
     */
    public void showScore(String firstTeamName, String secondTeamName, int firstTeamScore, int secondTeamScore){
        System.out.println("----Score----" );
        System.out.println(firstTeamName+ " "+ firstTeamScore+ "-"+ secondTeamScore + " " +secondTeamName);
    }
    /**
     * Displays the main menu to the user.
     */
    public void showMenu(){
        System.out.println("----------------------------------------");
        System.out.println("Welcome to the CS2 match results program");
        System.out.println("----------------------------------------");
    }
    /**
     * Displays a list of possible actions in the program to the user.
     */
    public void showOptions(){
        System.out.println("--------------------------");
        System.out.println("Choose what you want to do");
        System.out.println("--------------------------");
        System.out.println("1-Add a new match");
        System.out.println("2-Show all scores");
        System.out.println("3-View your nickname.");
        System.out.println("4-Turn off the program");
        System.out.println("5-Show all scores sorted by round difference");
  
    }
    /**
     * Displays an error message to the user
     * @param message The error message to be display.
     */
    public void showErrorMessage(String message){
        System.out.println("Error:" +message);
    }
    
    public void showMatchList(Model match){
        System.out.println(match.getFirstTeamName());
        System.out.println("------------");
        System.out.println(match.getFirstTeamScore());
        System.out.println("-------------------------------");
        System.out.println(match.getSecondTeamName());
        System.out.println("------------");
         System.out.println(match.getSecondTeamScore());
    }
    public void showMVPList(ArrayList<MVP> mvpPlayers){
        for(MVP element: mvpPlayers){
            System.out.println(element);
        }
    }
}
  

