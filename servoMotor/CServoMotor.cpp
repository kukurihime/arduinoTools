#include "Arduino.h"
#include "CServoMotor.h"

CServoMotor::CServoMotor(int pin, double pwmHz, int pwmResolution, double centerPulseWidth, double divPulseWidth, double initialAngle, double maxAngle, double minAngle):
  m_pin(pin),
  m_pwmHz(pwmHz),
  m_pwmResolution(pwmResolution),
  m_centerPulseWidth(centerPulseWidth),
  m_divPulseWidth(divPulseWidth),
  m_initialAngle(initialAngle),
  m_maxAngle(maxAngle),
  m_minAngle(minAngle)
{
  m_pwmResolutionPulseWidth = 1.0 / m_pwmHz / m_pwmResolution;
  m_currentAngle = m_initialAngle;
  m_targetAngle = m_currentAngle;
  
}

void CServoMotor::setTargetAngle(double target)
{
  if( target > m_maxAngle ){
    target = m_maxAngle;
  } else if( target < m_minAngle ){
    target = m_minAngle;
  }
  
  m_targetAngle = target;
}

void CServoMotor::moveToTargetAngle()
{
  analogWrite(m_pin, angleToDutyRatio( m_targetAngle ));
}

void CServoMotor::moveToInitialAngle()
{
  analogWrite(m_pin, angleToDutyRatio( m_initialAngle ));
}

int CServoMotor::angleToDutyRatio( double angle )
{
  double pulseWidth = m_centerPulseWidth + angle * m_divPulseWidth; 
  double ret = pulseWidth / m_pwmResolutionPulseWidth;
  return int(ret);
}
