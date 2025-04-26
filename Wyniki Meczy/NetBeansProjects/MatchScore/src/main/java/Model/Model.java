package Model;

import java.util.ArrayList;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 * The model represents data and is responsible for delivering and processing it
 * to other parts of the application.
 *
 * @author User Jakub Kos
 */
public class Model {

    /**
     * A string representing the name of the second team participating in the
     * match.
     */
    private String secondTeamName;
    /**
     * Represents the number of rounds won by the second team.
     */
    private int firstTeamScore;
    /**
     * Represents the number of rounds won by the first team.
     */
    private int secondTeamScore;
    /**
     * A string representing the name of the first team participating in the
     * match.
     */
    private String firstTeamName;
   
    private ArrayList<MVP> mvpPlayers = new ArrayList<>();
    /**
     * Method responsible for setting the new name of the first team.
     *
     * @param firstTeamName First team name.
     */
    public void setFirstTeamName(String firstTeamName) {
        this.firstTeamName = firstTeamName;
    }

    /**
     * Method responsible for setting the new name of the second team.
     *
     * @param secondTeamName Second team name.
     */
    public void setSecondTeamName(String secondTeamName) {
        this.secondTeamName = secondTeamName;
    }

    /**
     * The method responsible for setting the value of rounds won by the first
     * team.
     *
     * @param firstTeamScore Number of rounds won by the first team.
     */
    public void setFirstTeamScore(int firstTeamScore) {
        this.firstTeamScore = firstTeamScore;
    }

    /**
     * The method responsible for setting the value of rounds won by the second
     * team.
     *
     * @param secondTeamScore Number of rounds won by the second team.
     */
    public void setSecondTeamScore(int secondTeamScore) {
        this.secondTeamScore = secondTeamScore;
    }

    /**
     * Sets the name of the first team participating in the match.
     *
     * @param firstTeamName First team name.
     * @throws Exception The program returns an exception if the entered team
     * name is empty or null.
     */
    public void setFirstTeamNameFromConsole(String firstTeamName) throws Exception {
        if (!firstTeamName.isEmpty() && firstTeamName != null) {
            this.firstTeamName = firstTeamName;
        } else {
            throw new Exception("Invalid team name");
        }
    }

    /**
     * Sets the name of the second team participating in the match.
     *
     * @param secondTeamName Second team name.
     * @throws Exception The program returns an exception if the entered team
     * name is empty or null.
     */
    public void setSecondTeamNameFromConsole(String secondTeamName) throws Exception {
        if (!secondTeamName.isEmpty() && secondTeamName != null) {
            this.secondTeamName = secondTeamName;
        } else {
            throw new Exception("Invalid team name");
        }
    }

    /**
     * Sets the number of rounds won by the first team.
     *
     * @param firstTeamScore Rounds won in a match by the first team.
     * @throws Exception The program returns an exception if the number of
     * rounds won exceeds the specified range.
     */
    public void setFirstTeamScoreFromConsole(int firstTeamScore) throws Exception {
        if (firstTeamScore > 0 && firstTeamScore < 14) {
            this.firstTeamScore = firstTeamScore;
        } else {
            throw new Exception("Invalid number of points");
        }
    }

    /**
     * Sets the number of rounds won by the second team.
     *
     * @param secondTeamScore Rounds won in a match by the second team.
     * @throws Exception The program returns an exception if the number of
     * rounds won exceeds the specified range.
     */
    public void setSecondTeamScoreFromConsole(int secondTeamScore) throws Exception {
        if (secondTeamScore > 0 && secondTeamScore < 14) {
            this.secondTeamScore = secondTeamScore;
        } else {
            throw new Exception("Invalid number of points");
        }
    }
    
    public void isWinner(int firstTeamScore, int secondTeamScore)throws Exception{
        if(firstTeamScore == 13 || secondTeamScore != 13){
    }
    }
    /**
     * Gets the value from the field containing the first team name information.
     *
     * @return Returns the value of the first team name field.
     */
    public String getFirstTeamName() {
        return firstTeamName;
    }

    /**
     * Gets the value from the field containing the second team name
     * information.
     *
     * @return Returns the value of the second team name field.
     */
    public String getSecondTeamName() {
        return secondTeamName;
    }

    /**
     * Gets the value from the field containing information about the number of
     * rounds won by the first team.
     *
     * @return Returns the value of the field containing information about the
     * number of rounds won by the first team.
     */
    public int getFirstTeamScore() {
        return firstTeamScore;
    }

    /**
     * Gets the value from the field containing information about the number of
     * rounds won by the second team.
     *
     * @return Returns the value of the field containing information about the
     * number of rounds won by the second team.
     */
    public int getSecondTeamScore() {
        return secondTeamScore;
    }

    /**
     * Parametrized constructor.
     *
     * @param firstTeamName First team name.
     * @param secondTeamName Second team name.
     * @param firstTeamScore Number of rounds won by the first team.
     * @param secondTeamScore Number of rounds won by the second team.
     */
    public Model(String firstTeamName, String secondTeamName, int firstTeamScore, int secondTeamScore) {

        this.firstTeamName = firstTeamName;
        this.secondTeamName = secondTeamName;
        this.firstTeamScore = firstTeamScore;
        this.secondTeamScore = secondTeamScore;

    }

    /**
     * No-arg constructor.
     *
     */
    public Model() {

    }
    /**The method responsible for calculating the difference in the number of points between both teams
     * 
     * @return Returns the differences in round wins between teams
     */
    public int pointsDifference(){
        int difference;
        if(firstTeamScore > secondTeamScore){
            difference = firstTeamScore - secondTeamScore;
            return difference;
        }
        else{
            difference = secondTeamScore - firstTeamScore;
            System.out.println(difference);
            return difference;
        }
    }

}
