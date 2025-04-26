/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Model;

import java.util.ArrayList;

/**
 *
 * @author dell
 */
public class MVP {
    
    private String nickName;
    
    private int elimination;
    
    private int deaths;
    
    private ArrayList<MVP> mvpPlayers = new ArrayList<>();
    
    public void setNickName(String nickName){
        this.nickName = nickName;
    }
    
    public void setElimination(int elimination){
        this.elimination = elimination;
    }
    
    public void setDeaths(int deaths){
        this.deaths = deaths;
    }
    
    public String getNickName(String nickname){
        return nickname;
    }
    
    public int getElimination(int elimination){
        return elimination;
    }
    
    public int getDeaths(int deaths){
        return deaths;
    }
    
    public MVP(String nickname, int elimination, int deaths){
        this.nickName = nickName;
        this.elimination = elimination;
        this.deaths = deaths;
    }
    public MVP(){
        
    }
    @FunctionalInterface
    interface KDRATIO{
        double division(double a, double b);
    }
   
    
}
