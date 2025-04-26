/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package com.mycompany.scoreapp;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;

import javafx.scene.control.Button;
import javafx.scene.control.TextField;
/**
 * FXML Controller class
 *
 * @author User
 */
public class TestController implements Initializable {


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
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
    @FXML
    private void setMatchScoreAndBackToMenu(ActionEvent event) {
    }

}
