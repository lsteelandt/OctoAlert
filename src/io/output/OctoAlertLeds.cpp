/*
 * OctoAlertLeds.cpp
 *
 *  Created on: 14 juil. 2014
 *      Author: nicolaslambert
 */

#include "OctoAlertLeds.h"

OctoAlertLeds::OctoAlertLeds(uint16_t pin) :
		m_strip(new Adafruit_NeoPixel(41, pin, NEO_GRB + NEO_KHZ800)), m_smoothBlinkWay(0), m_currentBrightness(0), m_rFactor(
				100), m_gFactor(100), m_bFactor(100) {
	m_strip->begin();
	m_strip->setBrightness(70);
	m_strip->show(); // Initialize all pixels to 'off'
}

void OctoAlertLeds::colorAll(uint32_t c) {
	m_smoothBlinkWay = 0;
	for (uint16_t i = 0; i < m_strip->numPixels(); i++) {
		m_strip->setPixelColor(i, c);
	}
	m_strip->show();
}

void OctoAlertLeds::smoothBlink(int r, int g, int b) {
	int maxSmooth = max(max(r, g), b);
	if (maxSmooth == 0) {
		m_rFactor = 100;
		m_gFactor = 100;
		m_bFactor = 100;
	} else if (r == maxSmooth) {
		m_rFactor = 100;
		m_gFactor = g * 100 / r;
		m_bFactor = b * 100 / r;
	} else if (g == maxSmooth) {
		m_rFactor = r * 100 / g;
		m_gFactor = 100;
		m_bFactor = b * 100 / g;
	} else {
		m_rFactor = r * 100 / b;
		m_gFactor = g * 100 / b;
		m_bFactor = 100;
	}
	m_smoothBlinkWay = -1;
	m_currentBrightness = MAX_BRIGHT_BLINK;
}

void OctoAlertLeds::update(unsigned long currentTime) {
	if (m_smoothBlinkWay != 0) {
		int r = m_currentBrightness * m_rFactor / 100;
		int g = m_currentBrightness * m_gFactor / 100;
		int b = m_currentBrightness * m_bFactor / 100;
		uint32_t color = Adafruit_NeoPixel::Color(r, g, b);
		for (uint16_t i = 0; i < m_strip->numPixels(); i++) {
			m_strip->setPixelColor(i, color);
		}
		m_strip->show();
		m_currentBrightness += m_smoothBlinkWay;
		if (m_currentBrightness <= MIN_BRIGHT_BLINK || m_currentBrightness >= MAX_BRIGHT_BLINK) {
			m_smoothBlinkWay *= -1;
		}
	}
}
