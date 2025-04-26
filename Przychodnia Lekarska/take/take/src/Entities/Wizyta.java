package com.Take.Take;

import jakarta.persistence.Id;

import java.time.LocalDate;
import java.util.List;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Entity;
import jakarta.persistence.FetchType;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.ManyToOne;


@Entity
public class Wizyta {

	@Id
	@GeneratedValue(strategy=GenerationType.TABLE)
	private int Id;
	private LocalDate DataWizyty;
	
	@ManyToOne
	private Pacjent Pacjent;
	@ManyToOne
	private Choroba Choroba;
	@ManyToOne
	private Lekarz Lekarz;
	
	public Lekarz getLekarz() {
		return Lekarz;
	}
	
	public Pacjent getPacjent() {
		return Pacjent;
	}

	public void setPacjent(Pacjent pacjent) {
		Pacjent = pacjent;
	}
	
	public void setLekarz(Lekarz lekarz) {
		Lekarz = lekarz;
	}

	public Choroba getChoroba() {
		return Choroba;
	}

	public void setChoroba(Choroba choroba) {
		Choroba = choroba;
	}

	public int getId() {
		return Id;
	}

	public void setId(int id) {
		Id = id;
	}

	public LocalDate getDataWizyty() {
		return DataWizyty;
	}

	public void setDataWizyty(LocalDate dataWizyty) {
		DataWizyty = dataWizyty;
	}
	
	
}
