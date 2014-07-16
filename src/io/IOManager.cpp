/*
 * IOManager.cpp
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#include "IOManager.h"

IOManager::IOManager() :
		//----------------------------------------------------------------------------------------------------
		// Outputs
		m_octoAlertLeds(new OctoAlertLeds(44)),
		m_musicPlayer(new MusicPlayer()),
		m_startLed(new Led(48)),
		m_red1Led(new Led(40)),
		m_red2Led(new Led(38)),
		m_red3Led(new Led(36)),
		m_orangeLed(new Led(34)),
		m_greenLed(new Led(24)),

		//----------------------------------------------------------------------------------------------------
		// Inputs
		m_octoAlertButton(new Button(42)),
		m_countDownButton(new Button(46)),
		m_captainBarnaclesButton(new Button(28)),
		m_tweakButton(new Button(22)),
		m_kwaziiButton(new Button(30)),
		m_pesoButton(new Button(26))
{}

void IOManager::update(unsigned long currentTime) {
	// Outputs
	m_octoAlertLeds->update(currentTime);
	m_startLed->update(currentTime);

	// Inputs
	m_octoAlertButton->update(currentTime);
	m_countDownButton->update(currentTime);
	m_captainBarnaclesButton->update(currentTime);
	m_tweakButton->update(currentTime);
	m_kwaziiButton->update(currentTime);
	m_pesoButton->update(currentTime);
}
