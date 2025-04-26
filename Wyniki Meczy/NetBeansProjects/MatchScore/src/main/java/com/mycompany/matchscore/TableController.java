package com.mycompany.matchscore;


import Model.Model;
import java.io.IOException;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyCodeCombination;
import javafx.scene.input.KeyCombination;

public class TableController {

    @FXML
    private Button add;
    @FXML
    private Button remove;
    @FXML
    private TableView<Model> table;
    @FXML
    private TableColumn<Model, String> firstTeamName;
    @FXML
    private TableColumn<Model, String> secondTeamName;
    @FXML
    private TableColumn<Model, Integer> firstTeamScore;
    @FXML
    private TableColumn<Model, Integer> secondTeamScore;

    private final ObservableList<Model> data = FXCollections.observableArrayList();
    @FXML
    private Button back;

    public void initialize() {
        
        data.add(new Model("Vp", "Fnatic", 13, 7));
        data.add(new Model("Team3", "Team4", 1, 2));
        data.add( new Model("Navi", "Liquid", 13, 5));
        data.add( new Model("Mouse", "Faze",12,13 ));
        data.add( new Model("Heroic", "Apex",10,13 ));
        data.add( new Model("C9", "Renegedes",8,13 ));
        table.setItems(data);
        firstTeamName.setCellValueFactory(new PropertyValueFactory<>("firstTeamName"));
        firstTeamScore.setCellValueFactory(new PropertyValueFactory<>("firstTeamScore"));
        secondTeamScore.setCellValueFactory(new PropertyValueFactory<>("secondTeamScore"));
        secondTeamName.setCellValueFactory(new PropertyValueFactory<>("secondTeamName"));
         
    }

    @FXML
    private void add(ActionEvent event) {
        // Dodaj dane bezpośrednio do tabeli
        data.add(new Model("Vp", "Navi", 13, 5));
    }

    @FXML
    private void remove(ActionEvent event) {
        int index = table.getSelectionModel().getSelectedIndex();
        if (index != -1) {
            data.remove(index);
        }
    }

    public void returnToMenu() throws IOException {
        App.setRoot("primary.fxml");
    }
    private void handleAddAction(ActionEvent event) {
        // Dodaj dane bezpośrednio do tabeli w przypadku skrótu klawiszowego
        data.add(new Model("Vp", "Navi", 13, 5));
    }
    
}