package com.mycompany.scoreapp;

import java.io.IOException;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;

public class PrimaryController {
    
    @FXML
    private BorderPane bp;
    @FXML
    private AnchorPane ap;
    @FXML
    private Button addMatch;

    @FXML
    public void menu(MouseEvent event) {
         bp.setCenter(ap);
    }
    @FXML
    public void addNewMatch() throws IOException {
        App.setRoot("test2fxml");
    }

    @FXML
    public void page2(MouseEvent event) {
        loadPage("page2.fxml");
    }

    @FXML
    public void page3(MouseEvent event) {
        loadPage("showScore");
    }

    @FXML
    public void page4(MouseEvent event) {
        loadPage("showNick");
    }
    @FXML
    public void exit(MouseEvent event) {
    }
    
    public void loadPage(String page){
        Parent root = null;
        
        try {
            root = FXMLLoader.load(getClass().getResource(page+".fxml"));
        } catch (IOException ex) {
        }
        
     bp.setCenter(root);
    }

    
}
