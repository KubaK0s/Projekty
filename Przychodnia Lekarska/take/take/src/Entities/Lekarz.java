package com.Take.Take;

import jakarta.persistence.Id;

import java.util.ArrayList;
import java.util.List;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.ManyToMany;
import jakarta.persistence.OneToMany;

@Entity
public class Lekarz {

	@Id
	@GeneratedValue(strategy=GenerationType.TABLE)
	private int Id;
	private String Imie;
	private String Nazwisko;
	private String Specjalizacja;

	@OneToMany(mappedBy="lekarz")
	private List<Wizyta> Wizyty = new ArrayList<Wizyta>();
	
	public List<Wizyta> getWizyty() {
		return Wizyty;
	}
	public void setWizyty(List<Wizyta> wizyty) {
		Wizyty = wizyty;
	}

	public int getId() {
		return Id;
	}
	public void setId(int id) {
		Id = id;
	}
	public String getImie() {
		return Imie;
	}
	public void setImie(String imie) {
		Imie = imie;
	}
	public String getNazwisko() {
		return Nazwisko;
	}
	public void setNazwisko(String nazwisko) {
		Nazwisko = nazwisko;
	}
	public String getSpecjalizacja() {
		return Specjalizacja;
	}
	public void setSpecjalizacja(String specjalizacja) {
		Specjalizacja = specjalizacja;
	}
	

}
																																									