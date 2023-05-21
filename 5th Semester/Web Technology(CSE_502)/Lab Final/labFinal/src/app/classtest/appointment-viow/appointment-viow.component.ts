import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { AppointmentServiceService } from 'src/app/service/appointment-service.service';

@Component({
  selector: 'app-appointment-viow',
  templateUrl: './appointment-viow.component.html',
  styleUrls: ['./appointment-viow.component.css']
})
export class AppointmentViowComponent{
  patientName: string = '';
  contract:string = '';
  date: string = '';

  
  constructor(private router: Router, private appointmentService: AppointmentServiceService){}

  confirmAppointment() {
    console.log(this.appointmentService.getDoctorName());
    this.appointmentService.setPatientName(this.patientName);
    this.appointmentService.setContract(this.contract);
    this.router.navigate(['confirm'])
  }

  cancelAppointment(){
    this.appointmentService.setDoctorName('');
    this.router.navigate(['doctors']);
  }
}
