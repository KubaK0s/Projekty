/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package com.mycompany.matchscore;

import Model.Model;
import Model.Models;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class TestController {

    @FXML
    private TextField firstTeamNameId;
    @FXML
    private TextField secondTeamNameId;
    @FXML
    private TextField firstTeamScoreId;
    @FXML
    private TextField secondTeamScoreId;
    @FXML
    private Button confirmButton;

    private List<Model> matches = new ArrayList<>();
    
    private TableController tableController;
    
    public void setTableController(TableController tableController) {
        this.tableController = tableController;
    }
    public Models models;

    public void setModels(Models models) {
        this.models = models;
    }
    @FXML
    public void setMatchScoreAndBackToMenu() throws IOException {
        String firstTeamName = firstTeamNameId.getText();
        String secondTeamName = secondTeamNameId.getText();
        int firstTeamScore = 0;
        int secondTeamScore = 0;

        try {
            validateTextFieldNotEmpty(firstTeamName, "The first team name cannot be empty.");
            validateTextFieldNotEmpty(secondTeamName, "The second team name cannot be empty.");

            validateIntegerInput(firstTeamScoreId.getText(), "Points must be an integer.");
            validateIntegerInput(secondTeamScoreId.getText(), "Points must be an integer.");

            firstTeamScore = Integer.parseInt(firstTeamScoreId.getText());
            secondTeamScore = Integer.parseInt(secondTeamScoreId.getText());

            if (firstTeamScore < 0 || firstTeamScore > 13 || secondTeamScore < 0 || secondTeamScore > 13) {
                throw new IllegalArgumentException("Points must be between 0 and 13.");
            }

            Model match = new Model(firstTeamName, secondTeamName, firstTeamScore, secondTeamScore);
            matches.add(match);

         

            App.setRoot("primary.fxml");
        } catch (IllegalArgumentException e) {
            showErrorAlert("Error: " + e.getMessage());
        } catch (Exception e) {
            showErrorAlert("Another error: " + e.getMessage());
        }
    }

    private void validateTextFieldNotEmpty(String text, String errorMessage) {
        if (text.isEmpty()) {
            showErrorAlert(errorMessage);
        }
    }

    private void showErrorAlert(String message) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Error");
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    private void validateIntegerInput(String input, String errorMessage) {
        try {
            Integer.parseInt(input);
        } catch (NumberFormatException e) {
            showErrorAlert(errorMessage);
            throw e;
        }
    }

//    void setModels(Models models) {
//        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
//    }
}