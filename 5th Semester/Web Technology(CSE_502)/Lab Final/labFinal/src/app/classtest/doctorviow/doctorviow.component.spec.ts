import { ComponentFixture, TestBed } from '@angular/core/testing';

import { DoctorviowComponent } from './doctorviow.component';

describe('DoctorviowComponent', () => {
  let component: DoctorviowComponent;
  let fixture: ComponentFixture<DoctorviowComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ DoctorviowComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(DoctorviowComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
