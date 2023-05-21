import { Component } from '@angular/core';
import { DoctorComponent } from '../doctor/doctor.component';
import { Router } from '@angular/router';
import { AppointmentServiceService } from 'src/app/service/appointment-service.service';

@Component({
  selector: 'app-doctorviow',
  templateUrl: './doctorviow.component.html',
  styleUrls: ['./doctorviow.component.css']
})
export class DoctorviowComponent {
  constructor(private appointmentService: AppointmentServiceService, private router:Router) {}



  doctors: DoctorComponent[] = [{name: "Rakibbul Islam", hospitalName:"IBS"}, {name:"Araf Ahmed", hospitalName: "Prime Hospital"}, {name:"Afnaf Mubaasshir Mobin", hospitalName:"Anam Hospital"}];

  bookAppointment(doctorName: string) {
    this.appointmentService.setDoctorName(doctorName);
    this.router.navigate(['appointment'])
  }

  getAppointmentInfo(){
  }



}
