module com.mycompany.matchscore {
    requires javafx.controls;
    requires javafx.fxml;

    opens com.mycompany.matchscore to javafx.fxml;
    opens Model to javafx.base; // Otwieramy pakiet Model

    exports com.mycompany.matchscore;
    exports Model;
}

