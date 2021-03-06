/** @addtogroup rtc_defines
 *
 * @brief <b>Access functions for the NRF51 Real Time Counter Controller </b>
 * @ingroup NRF51_defines
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxims@google.com>
 *
 */

/*
 * This file is part of the unicore-mx project.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <unicore-mx/nrf/rtc.h>

/** @brief RTC set Prescaler value.
 *
 * @details The clock needs to be stopped for this to have any effect.
 *
 * @param[in] rtc uint32_t RTC base
 * @param[in] presc uint16_t 12 bit prescaler value.
 */
void rtc_set_prescaler(uint32_t rtc, uint16_t presc)
{
	RTC_PRESCALER(rtc) = presc & 0xfff;
}

/** @brief RTC get Counter value.
 *
 * @param[in] rtc uint32_t RTC base
 */
uint32_t rtc_get_counter(uint32_t rtc)
{
	return RTC_COUNTER(rtc);
}

/** @brief Enable peripheral interrupts
 *
 * @param[in] rtc uint32_t RTC base
 * @param[in] mask uint32_t which interrupts to enable
 */
void rtc_enable_interrupts(uint32_t rtc, uint32_t mask)
{
	RTC_INTENSET(rtc) = mask;
}

/** @brief Disable peripheral interrupts
 *
 * @param[in] rtc uint32_t RTC base
 * @param[in] mask uint32_t which interrupts to disable
 */
void rtc_disable_interrupts(uint32_t rtc, uint32_t mask)
{
	RTC_INTENCLR(rtc) = mask;
}

/** @brief Enable events
 *
 * @param[in] rtc uint32_t RTC base
 * @param[in] mask uint32_t which events to enable
 */
void rtc_enable_events(uint32_t rtc, uint32_t mask)
{
	RTC_EVTENSET(rtc) = mask;
}

/** @brief Disable events
 *
 * @param[in] rtc uint32_t RTC base
 * @param[in] mask uint32_t which events to disable
 */
void rtc_disable_events(uint32_t rtc, uint32_t mask)
{
	RTC_EVTENCLR(rtc) = mask;
}

/** @brief Start the RTC
 *
 * @param[in] rtc uint32_t RTC base
 */
void rtc_start(uint32_t rtc)
{
	RTC_TASK_START(rtc) = 1;
}

/** @brief Stop the RTC
 *
 * @param[in] rtc uint32_t RTC base
 */
void rtc_stop(uint32_t rtc)
{
	RTC_TASK_STOP(rtc) = 1;
}

/** @brief Clear the RTC
 *
 * @param[in] rtc uint32_t RTC base
 */
void rtc_clear(uint32_t rtc)
{
	RTC_TASK_CLEAR(rtc) = 1;
}

/** @brief Set compare register
 *
 * @param[in] rtc uint32_t RTC base
 * @param[in] cmp uint8_t compare number (0-3)
 * @param[in] value uint32_t compare value
 */
void rtc_set_compare(uint32_t rtc, uint8_t cmp, uint32_t value)
{
	if (cmp < 4)
		RTC_CC(rtc, cmp) = value;
}
