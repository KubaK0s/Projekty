module com.mycompany.scoreapp {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.base;

    opens com.mycompany.scoreapp to javafx.fxml;
    exports com.mycompany.scoreapp;
}
