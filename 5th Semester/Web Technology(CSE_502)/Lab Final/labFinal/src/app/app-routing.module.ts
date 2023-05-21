import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { DoctorviowComponent } from './classtest/doctorviow/doctorviow.component';
import { AppointmentViowComponent } from './classtest/appointment-viow/appointment-viow.component';
import { ConfirmViewComponent } from './classtest/confirm-view/confirm-view.component';

const routes: Routes = [
  {path:"", component: DoctorviowComponent},
  {path:"doctors", component: DoctorviowComponent},
  {path:"appointment", component: AppointmentViowComponent},
  {path:"confirm", component: ConfirmViewComponent},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
