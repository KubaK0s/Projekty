package Controller;

import java.util.Scanner;
import Model.Model;
import View.View;
import Model.MVP;

import java.util.ArrayList;
import java.util.List;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 * The controller is responsible for interacting with the user and processing
 * his requests.
 *
 * @author User Jakub Kos
 */
public class Controller {

    private Model score;

    public void setScore(Model score) {
        this.score = score;
    }

    public void setScoreMenu(View scoreMenu) {
        this.scoreMenu = scoreMenu;
    }

    public Model getScore() {
        return score;
    }

    public View getScoreMenu() {
        return scoreMenu;
    }
    private View scoreMenu;
   

 
    
  

    /**
     *
     * @param score Object created
     * @param scoreMenu Object created
     */
    public Controller(Model score, View scoreMenu) {

        this.score = score;
        this.scoreMenu = scoreMenu;
       
    }

    /**
     * Method responsible for setting the new name of the first team.
     *
     * @param firstTeamName First team name.
     */
    public void setFirstTeamName(String firstTeamName) {
        score.setFirstTeamName(firstTeamName);
    }

    /**
     * Method responsible for setting the new name of the second team.
     *
     * @param secondTeamName Second team name.
     */
    public void setSecondTeamName(String secondTeamName) {
        score.setSecondTeamName(secondTeamName);
    }

    /**
     * The method responsible for setting the value of rounds won by the first
     * team.
     *
     * @param firstTeamScore Number of rounds won by the first team.
     */
    public void setFirstTeamScore(int firstTeamScore) {
        score.setFirstTeamScore(firstTeamScore);
    }

    /**
     * The method responsible for setting the value of rounds won by the second
     * team.
     *
     * @param secondTeamScore Number of rounds won by the second team.
     */
    public void setSecondTeamScore(int secondTeamScore) {
        score.setSecondTeamScore(secondTeamScore);
    }

    /**
     * Gets the value from the field containing the first team name information
     *
     * @param firstTeamName First team name.
     * @return Returns the value of the first team name field.
     */
    public String getFirstTeamName(String firstTeamName) {
        return score.getFirstTeamName();
    }

    /**
     * The method responsible for determining the number of rounds won by the
     * first team. The method includes catching exceptions and displaying error
     * messages in case of incorrect data setting.
     *
     *
     */
    /**
     * Gets the value from the field containing information about the number of
     * rounds won by the first team.
     *
     * @param firstTeamScore Number of rounds won by the first team.
     * @return Returns the value of the field containing information about the
     * number of rounds won by the first team.
     */
    public int getFirstTeamScore(int firstTeamScore) {
        return score.getFirstTeamScore();
    }

    /**
     * Gets the value from the field containing the second team name
     * information.
     *
     * @param secondTeamName Second team name.
     * @return Returns the value of the second team name field.
     */
    public String getSecondTeamName(String secondTeamName) {
        return score.getSecondTeamName();
    }

    /**
     * Gets the value from the field containing information about the number of
     * rounds won by the second team.
     *
     * @param secondTeamScore Number of rounds won by the second team.
     * @return Returns the value of the field containing information about the
     * number of rounds won by the second team.
     */
    public int getSecondTeamScore(int secondTeamScore) {
        return score.getSecondTeamScore();
    }
    
    /**User adding match data and catching exceptions.
     * 
     */
    public void setMatchScore() {
            
        while (true) {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter first team name: ");
            String firstTeamName = scanner.nextLine();
            try {
                score.setFirstTeamNameFromConsole(firstTeamName);
                break;
            } catch (Exception e) {
                scoreMenu.showErrorMessage(e.getMessage());
               
            }
        }
        while(true){
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter second team name: ");
            String secondTeamName = scanner.nextLine();
            try {
                score.setSecondTeamNameFromConsole(secondTeamName);
                break;
            } catch (Exception e) {
                scoreMenu.showErrorMessage(e.getMessage());
            }
        }   
        while(true){
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter first team score: ");
            int firstTeamScore = scanner.nextInt();
            try {
                score.setFirstTeamScoreFromConsole(firstTeamScore);
                break;
            } catch (Exception e) {
                scoreMenu.showErrorMessage(e.getMessage());
            }
        }
        while(true){
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter second team score: ");
            int secondTeamScore = scanner.nextInt();
            try {
                score.setSecondTeamScoreFromConsole(secondTeamScore);
                break;
            } catch (Exception e) {
                scoreMenu.showErrorMessage(e.getMessage());
            }

          
        }

    }
    /**
     * Method responsible for displaying the match result.
     *
     */
    public void showMatchScore() {

        scoreMenu.showScore(score.getFirstTeamName(), score.getSecondTeamName(), score.getFirstTeamScore(), score.getSecondTeamScore());
    }
    /**The method responsible for calculating the difference in the number of points between both teams
     * 
     * @return Returns the differences in round wins between teams.
     */
    public int pointsDifference(){
       return  score.pointsDifference();
        
    }
    
    
}


   

