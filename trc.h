/**
 * @file register_spec.h
 * @brief Register definitions, bit-field macros, and function prototypes
 * for the device based on the provided specifications.
 *
 * NOTE: This header assumes the presence of standard integer types from <stdint.h>.
 */

#ifndef REGISTER_SPEC_H
#define REGISTER_SPEC_H

#include <stdint.h>

/*
 * ==============================================================================
 * TYPE DEFINITIONS
 * ==============================================================================
 */

// Define 'uint32' to match the function signature specification (typically uint32_t)
typedef uint32_t uint32;

/*
 * ==============================================================================
 * REGISTER ADDRESS DEFINITIONS
 * ==============================================================================
 */

// SET 1: SWITCH Register Address
#define REG_ADDR_SWITCH             (0x01)

// SET 2: RF_GAIN_1 Register Address
#define REG_ADDR_RF_GAIN_1          (0x03)

// SET 3: RF_GAIN_2 Register Address
#define REG_ADDR_RF_GAIN_2          (0x04)

// SET 4: MIXER/GAIN Enable Register Address
#define REG_ADDR_MIXER_GAIN         (0x17)

// SET 5: Power on self test results Register Address (read only)
#define REG_ADDR_POST_RESULTS       (0x20)

// SET 6: Mixer Temperature Register Address (read only)
#define REG_ADDR_MIXER_TEMPERATURE  (0x27)

// SET 7: TBIT (special case) Register Address
#define REG_ADDR_TBIT               (0x0B)


/*
 * ==============================================================================
 * CONFIGURATION AND BIT-FIELD MACROS
 * ==============================================================================
 */

// ------------------------------------------------------------------------------
// SET 1: SWITCH Macros (Register Address: 0x01)
// ------------------------------------------------------------------------------
#define SWITCH_TX_HPA_ENABLE        (0x1)
#define SWITCH_RX_LNA_ENABLE        (0x2)
#define SWITCH_TRC_ENABLE           (0x4)

// ------------------------------------------------------------------------------
// SET 2: RF_GAIN_1 Macros (Register Address: 0x03)
// ------------------------------------------------------------------------------
// Must be set value (likely reserved or default required bits)
#define RF_GAIN_1_MUST_SET          (0x38000000)

// GAIN1 Field (4 bits, shifted to position 8-11: 0xX00)
#define RF_GAIN_1_GAIN1_0           (0x000)
#define RF_GAIN_1_GAIN1_1           (0x100)
#define RF_GAIN_1_GAIN1_2           (0x200)
#define RF_GAIN_1_GAIN1_3           (0x300)
#define RF_GAIN_1_GAIN1_4           (0x400)
#define RF_GAIN_1_GAIN1_5           (0x500)
#define RF_GAIN_1_GAIN1_6           (0x600)
#define RF_GAIN_1_GAIN1_7           (0x700)
#define RF_GAIN_1_GAIN1_8           (0x800)
#define RF_GAIN_1_GAIN1_9           (0x900)
#define RF_GAIN_1_GAIN1_10          (0xA00)
#define RF_GAIN_1_GAIN1_11          (0xB00)
#define RF_GAIN_1_GAIN1_12          (0xC00)
#define RF_GAIN_1_GAIN1_13          (0xD00)
#define RF_GAIN_1_GAIN1_14          (0xE00)
#define RF_GAIN_1_GAIN1_15          (0xF00)

// GAIN2 Field (4 bits, shifted to position 12-15: 0xX000)
#define RF_GAIN_1_GAIN2_0           (0x0000)
#define RF_GAIN_1_GAIN2_1           (0x1000)
#define RF_GAIN_1_GAIN2_2           (0x2000)
#define RF_GAIN_1_GAIN2_3           (0x3000)
#define RF_GAIN_1_GAIN2_4           (0x4000)
#define RF_GAIN_1_GAIN2_5           (0x5000)
#define RF_GAIN_1_GAIN2_6           (0x6000)
#define RF_GAIN_1_GAIN2_7           (0x7000)
#define RF_GAIN_1_GAIN2_8           (0x8000)
#define RF_GAIN_1_GAIN2_9           (0x9000)
#define RF_GAIN_1_GAIN2_10          (0xA000)
#define RF_GAIN_1_GAIN2_11          (0xB000)
#define RF_GAIN_1_GAIN2_12          (0xC000)
#define RF_GAIN_1_GAIN2_13          (0xD000)
#define RF_GAIN_1_GAIN2_14          (0xE000)
#define RF_GAIN_1_GAIN2_15          (0xF000)

// GAIN3 Field (4 bits, shifted to position 16-19: 0xX0000)
#define RF_GAIN_1_GAIN3_0           (0x00000)
#define RF_GAIN_1_GAIN3_1           (0x10000)
#define RF_GAIN_1_GAIN3_2           (0x20000)
#define RF_GAIN_1_GAIN3_3           (0x30000)
#define RF_GAIN_1_GAIN3_4           (0x40000)
#define RF_GAIN_1_GAIN3_5           (0x50000)
#define RF_GAIN_1_GAIN3_6           (0x60000)
#define RF_GAIN_1_GAIN3_7           (0x70000)
#define RF_GAIN_1_GAIN3_8           (0x80000)
#define RF_GAIN_1_GAIN3_9           (0x90000)
#define RF_GAIN_1_GAIN3_10          (0xA0000)
#define RF_GAIN_1_GAIN3_11          (0xB0000)
#define RF_GAIN_1_GAIN3_12          (0xC0000)
#define RF_GAIN_1_GAIN3_13          (0xD0000)
#define RF_GAIN_1_GAIN3_14          (0xE0000)
#define RF_GAIN_1_GAIN3_15          (0xF0000)

// GAIN4 Field (4 bits, shifted to position 20-23: 0xX00000)
#define RF_GAIN_1_GAIN4_0           (0x000000)
#define RF_GAIN_1_GAIN4_1           (0x100000)
#define RF_GAIN_1_GAIN4_2           (0x200000)
#define RF_GAIN_1_GAIN4_3           (0x300000)
#define RF_GAIN_1_GAIN4_4           (0x400000)
#define RF_GAIN_1_GAIN4_5           (0x500000)
#define RF_GAIN_1_GAIN4_6           (0x600000)
#define RF_GAIN_1_GAIN4_7           (0x700000)
#define RF_GAIN_1_GAIN4_8           (0x800000)
#define RF_GAIN_1_GAIN4_9           (0x900000)
#define RF_GAIN_1_GAIN4_10          (0xA00000)
#define RF_GAIN_1_GAIN4_11          (0xB00000)
#define RF_GAIN_1_GAIN4_12          (0xC00000)
#define RF_GAIN_1_GAIN4_13          (0xD00000)
#define RF_GAIN_1_GAIN4_14          (0xE00000)
#define RF_GAIN_1_GAIN4_15          (0xF00000)

// PHASE Field (3 bits, shifted to position 24-26: 0xX000000)
#define RF_GAIN_1_PHASE_0           (0x0000000)
#define RF_GAIN_1_PHASE_1           (0x1000000)
#define RF_GAIN_1_PHASE_2           (0x2000000)
#define RF_GAIN_1_PHASE_3           (0x3000000)
#define RF_GAIN_1_PHASE_4           (0x4000000)
#define RF_GAIN_1_PHASE_5           (0x5000000)
#define RF_GAIN_1_PHASE_6           (0x6000000)
#define RF_GAIN_1_PHASE_7           (0x7000000) // Appears twice in spec, defined once.

// ------------------------------------------------------------------------------
// SET 3: RF_GAIN_2 Macros (Register Address: 0x04)
// ------------------------------------------------------------------------------
// Must be set value
#define RF_GAIN_2_MUST_SET          (0x60C)

// PARABOLIC_FREQUENCY Field (4 bits, shifted to position 22-25: 0xX00000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_0   (0x0000000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_1   (0x0400000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_2   (0x0800000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_3   (0x0C00000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_4   (0x1000000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_5   (0x1400000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_6   (0x1800000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_7   (0x1C00000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_8   (0x2000000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_9   (0x2400000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_10  (0x2800000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_11  (0x2C00000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_12  (0x3000000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_13  (0x3400000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_14  (0x3800000)
#define RF_GAIN_2_PARABOLIC_FREQUENCY_15  (0x3C00000)

// PARABOLIC_DEPTH Field (3 bits, shifted to position 26-28: 0xX000000)
#define RF_GAIN_2_PARABOLIC_DEPTH_0       (0x00000000)
#define RF_GAIN_2_PARABOLIC_DEPTH_1       (0x4000000)
#define RF_GAIN_2_PARABOLIC_DEPTH_2       (0x8000000)
#define RF_GAIN_2_PARABOLIC_DEPTH_3       (0xC000000)
#define RF_GAIN_2_PARABOLIC_DEPTH_4       (0x10000000)
#define RF_GAIN_2_PARABOLIC_DEPTH_5       (0x14000000)
#define RF_GAIN_2_PARABOLIC_DEPTH_6       (0x18000000)
#define RF_GAIN_2_PARABOLIC_DEPTH_7       (0x1C000000)

// UPSLODE Field (3 bits, shifted to position 29-31: 0xX0000000)
#define RF_GAIN_2_UPSLODE_0         (0x00000000)
#define RF_GAIN_2_UPSLODE_1         (0x20000000)
#define RF_GAIN_2_UPSLODE_2         (0x40000000)
#define RF_GAIN_2_UPSLODE_3         (0x60000000)
#define RF_GAIN_2_UPSLODE_4         (0x80000000)
#define RF_GAIN_2_UPSLODE_5         (0xA0000000)
#define RF_GAIN_2_UPSLODE_6         (0xC0000000)
#define RF_GAIN_2_UPSLODE_7         (0xE0000000)

// ------------------------------------------------------------------------------
// SET 4: MIXER/GAIN Enable Macros (Register Address: 0x17)
// ------------------------------------------------------------------------------
#define MIXER_GAIN_RF_DISABLE       (0x0)
#define MIXER_GAIN_RF_ENABLE        (0x00FFFFFF)

// ------------------------------------------------------------------------------
// SET 5: Power on self test results Macros (Register Address: 0x20)
// ------------------------------------------------------------------------------
#define POST_RESULTS_MASK           (0x3FF)

// ------------------------------------------------------------------------------
// SET 6: Mixer Temperature Macros (Register Address: 0x27)
// ------------------------------------------------------------------------------
#define MIXER_TEMP_MASK             (0xF)


/*
 * ==============================================================================
 * FUNCTION PROTOTYPES
 * ==============================================================================
 */

/**
 * @brief Writes the configuration to the SWITCH register (0x01).
 * @param configuration The 32-bit value containing the desired bit settings (e.g., TX_HPA_ENABLE).
 * @return 0 on success, non-zero on error.
 */
int write_switch(uint32 configuration);

/**
 * @brief Writes the configuration to the RF_GAIN_1 register (0x03).
 * @param configuration The 32-bit value containing the desired gain and phase settings.
 * @return 0 on success, non-zero on error.
 */
int write_rf_gain_1(uint32 configuration);

/**
 * @brief Writes the configuration to the RF_GAIN_2 register (0x04).
 * @param configuration The 32-bit value containing the desired parabolic settings.
 * @return 0 on success, non-zero on error.
 */
int write_rf_gain_2(uint32 configuration);

/**
 * @brief Writes the configuration to the MIXER/GAIN Enable register (0x17).
 * @param configuration The 32-bit value, typically RF_DISABLE or RF_ENABLE.
 * @return 0 on success, non-zero on error.
 */
int write_mixer_gain(uint32 configuration);

/**
 * @brief Reads the Power on self test results register (0x20).
 * The return value should be masked with POST_RESULTS_MASK (0x1FF).
 * @return The 32-bit register value, or a negative error code.
 */
int read_power_on_self_test_results();

/**
 * @brief Reads the Mixer Temperature register (0x27).
 * The return value should be masked with MIXER_TEMP_MASK (0xF).
 * @return The 32-bit register value, or a negative error code.
 */
int read_mixer_temp();

/**
 * @brief Reads the TBIT register (0x0B), which is a special case requiring a channel input.
 * @param channel The channel number to read TBIT data from.
 * @return The TBIT result for the specified channel, or a negative error code.
 */
int read_tbit(int channel);

#endif // REGISTER_SPEC_H
