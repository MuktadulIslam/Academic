import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { DoctorviowComponent } from './classtest/doctorviow/doctorviow.component';
import { DoctorComponent } from './classtest/doctor/doctor.component';
import { AppointmentViowComponent } from './classtest/appointment-viow/appointment-viow.component';
import { ConfirmViewComponent } from './classtest/confirm-view/confirm-view.component';
import { FormsModule } from '@angular/forms';

@NgModule({
  declarations: [
    AppComponent,
    DoctorviowComponent,
    DoctorComponent,
    AppointmentViowComponent,
    ConfirmViewComponent,
    DoctorComponent
  ],
  imports: [
    BrowserModule,
    FormsModule,
    AppRoutingModule
  ],
  providers: [DoctorviowComponent, AppointmentViowComponent, ConfirmViewComponent],
  bootstrap: [AppComponent]
})
export class AppModule { }
