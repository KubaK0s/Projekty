/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Model;

/**
 *
 * @author User Jakub Kos
 */
public class OwnExceptions extends Exception {

    /**
     * Non-parameter constructor
     *
     */
    public OwnExceptions() {

    }

    /**
     * Exception class constructor
     *
     * @param message The error message.
     */
    public OwnExceptions(String message) {

        super(message);
    }
}
