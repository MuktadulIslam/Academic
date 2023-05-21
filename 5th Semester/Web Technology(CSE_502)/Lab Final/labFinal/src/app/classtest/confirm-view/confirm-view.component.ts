import { Component } from '@angular/core';
import { AppointmentServiceService } from 'src/app/service/appointment-service.service';

@Component({
  selector: 'app-confirm-view',
  templateUrl: './confirm-view.component.html',
  styleUrls: ['./confirm-view.component.css']
})
export class ConfirmViewComponent {
  patientName: string = '';
  doctorName: string = '';
  contract: string = '';

  constructor(private appoinementService:AppointmentServiceService){
    this.patientName = appoinementService.getPatientName();
    this.doctorName = appoinementService.getDoctorName();
    this.contract = appoinementService.getContract();
  }
}
