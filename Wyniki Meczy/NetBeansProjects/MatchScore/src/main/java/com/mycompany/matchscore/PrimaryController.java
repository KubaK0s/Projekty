package com.mycompany.matchscore;

import Model.Models;
import java.io.IOException;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyCodeCombination;
import javafx.scene.input.KeyCombination;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class PrimaryController {

    private BorderPane bp;
    private AnchorPane ap;
    @FXML
    private Button addMatch;
    @FXML
    private Button showScore;
    @FXML
    private Button quit;
    private TableController tableController;

    public void setTableController(TableController tableController) {
        this.tableController = tableController;
    }

    public void menu(MouseEvent event) {
        bp.setCenter(ap);
    }
    public Models models;

    public void setModels(Models models) {
        this.models = models;
    }
    

    @FXML
    public void addNewMatch() throws IOException {
    FXMLLoader loader = new FXMLLoader(getClass().getResource("addMatch.fxml"));
    Parent root = loader.load();

    // Przekazuj instancję Models do TestController
    TestController testController = loader.getController();
    testController.setModels(models);

    App.setRoot("addMatch.fxml");
}

    @FXML
    public void showAllScore() throws IOException {
        App.setRoot("showScore.fxml");
    }

    @FXML
    public void handleExit() {
        System.exit(0);
    }

    @FXML
    private void menu(ActionEvent event) {
    }

    @FXML
    private void exit(ActionEvent event) {
    }
//    @FXML
//    private void initialize() {
//        // Ustawienie skrótu klawiszowego dla przycisku "Add Match" (Ctrl + M)
//        KeyCodeCombination addMatchCombination = new KeyCodeCombination(KeyCode.M, KeyCombination.CONTROL_DOWN);
//         addMatch.getScene().addEventHandler(KeyEvent.KEY_PRESSED, event -> {
//            if (addMatchCombination.match(event)) {
//                try {
//                    addNewMatch();
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//        });
//
//
//        // Ustawienie skrótu klawiszowego dla przycisku "Show Score" (Ctrl + S)
//        KeyCodeCombination showScoreCombination = new KeyCodeCombination(KeyCode.S, KeyCombination.CONTROL_DOWN);
//        showScore.getScene().addEventHandler(KeyEvent.KEY_PRESSED, event -> {
//            if (showScoreCombination.match(event)) {
//                try {
//                    showAllScore();
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//        });
//
//        // Ustawienie skrótu klawiszowego dla przycisku "Quit" (Ctrl + Q)
//        KeyCodeCombination quitCombination = new KeyCodeCombination(KeyCode.Q, KeyCombination.CONTROL_DOWN);
//        quit.getScene().addEventHandler(KeyEvent.KEY_PRESSED, event -> {
//            if (quitCombination.match(event)) {
//                handleExit();
//            }
//        });
    }


