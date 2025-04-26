package com.Take.Take;

import jakarta.persistence.Column;
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
public class Choroba {

	@Id
	@GeneratedValue(strategy=GenerationType.TABLE)
	private int Id;
	private String NazwaChoroby;
	@OneToMany
	private List<Pacjent> Pacjenci;
	
	@OneToMany(cascade=CascadeType.ALL,mappedBy="choroba")
	private List<Wizyta> Wizyta = new ArrayList<Wizyta>();
	
	public List<Wizyta> getWizyta() {
		return Wizyta;
	}

	public void setWizyta(List<Wizyta> wizyta) {
		Wizyta = wizyta;
	}

	public List<Pacjent> getPacjenci() {
		return Pacjenci;
	}

	public void setPacjenci(List<Pacjent> pacjenci) {
		Pacjenci = pacjenci;
	}

	public int getId() {
		return Id;
	}

	public void setId(int id) {
		Id = id;
	}

	public String getNazwaChoroby() {
		return NazwaChoroby;
	}

	public void setNazwaChoroby(String nazwaChoroby) {
		NazwaChoroby = nazwaChoroby;
	}
	
}
