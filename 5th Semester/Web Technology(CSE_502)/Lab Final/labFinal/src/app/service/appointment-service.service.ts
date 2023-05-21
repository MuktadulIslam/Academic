import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class AppointmentServiceService {
  doctorName: string = '';
  patientName: string = '';
  contract: string = '';

  setDoctorName(name: string) {
    this.doctorName = name;
  }

  getDoctorName(){
    return this.doctorName;
  }

  setPatientName(name: string) {
    this.patientName = name;
  }

  getPatientName(){
    return this.patientName;
  }

  setContract(contract: string) {
    this.contract = contract;
  }

  getContract(){
    return this.contract;
  }

  constructor() { }
}
