/*
 * OctoAlertLeds.h
 *
 *  Created on: 14 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef OCTOALERTLEDS_H_
#define OCTOALERTLEDS_H_

#include <Adafruit_NeoPixel.h>
#include "LedMapping.h"

class OctoAlertLeds {
public:
	OctoAlertLeds(uint16_t pin);
	void update();
	void setColor(uint64_t ledMask, uint32_t color, bool switchOffOthers = true);
	void setColor(uint64_t ledMask, uint8_t r, uint8_t g, uint8_t b, bool switchOffOthers = true);
	void off(uint64_t ledMask);
private:
	Adafruit_NeoPixel * const m_strip;
	const uint32_t m_off;
};

#endif /* OCTOALERTLEDS_H_ */
