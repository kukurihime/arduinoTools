#ifndef CSERVOMOTOR_H
#define CSERVOMOTOR_H

class CServoMotor{
  public:
    CServoMotor(int pin, double pwmHz, int pwmResolution, double centerPulseWidth, double divPulseWidth, double initialAngle, double maxAngle, double minAngle);
    void setTargetAngle( double angle );
    void moveToTargetAngle();
    void moveToInitialAngle();
  private:
    int m_pin;
    double m_pwmHz;
    int m_pwmResolution;
    double m_centerPulseWidth;  // pwm pulse width of 0.0deg(center)(unit:sec)
    double m_divPulseWidth; // per 1.0deg
    double m_pwmResolutionPulseWidth; // 1.0 / m_pwmHZ / m_pwmResolution
    
    double m_currentAngle;
    double m_targetAngle;
    double m_initialAngle;
    double m_maxAngle;
    double m_minAngle;

    int angleToDutyRatio( double angle );
};

#endif
