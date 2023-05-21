import { ComponentFixture, TestBed } from '@angular/core/testing';

import { AppointmentViowComponent } from './appointment-viow.component';

describe('AppointmentViowComponent', () => {
  let component: AppointmentViowComponent;
  let fixture: ComponentFixture<AppointmentViowComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ AppointmentViowComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(AppointmentViowComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
