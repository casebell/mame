// license:BSD-3-Clause
// copyright-holders:David Haywood
#ifndef MAME_INCLUDES_BFM_SC5_H
#define MAME_INCLUDES_BFM_SC5_H

#pragma once

#include "includes/bfm_sc4.h"
#include "cpu/m68000/m68000.h"

class bfm_sc5_state : public bfm_sc45_state
{
public:
	bfm_sc5_state(const machine_config &mconfig, device_type type, const char *tag)
		: bfm_sc45_state(mconfig, type, tag)
		, m_maincpu(*this, "maincpu")
	{ }

	void init_sc5();

	void bfm_sc5(machine_config &config);

protected:
	void sc5_map(address_map &map);

	required_device<m68000_base_device> m_maincpu;

	DECLARE_READ8_MEMBER( sc5_10202F0_r );
	DECLARE_WRITE8_MEMBER( sc5_10202F0_w );
	DECLARE_WRITE16_MEMBER( sc5_duart_w );

	DECLARE_READ8_MEMBER( sc5_mux1_r );
	DECLARE_WRITE8_MEMBER( sc5_mux1_w );
	DECLARE_WRITE8_MEMBER( sc5_mux2_w );

	DECLARE_WRITE_LINE_MEMBER(bfm_sc5_duart_irq_handler);
	DECLARE_WRITE_LINE_MEMBER(bfm_sc5_duart_txa);
	uint8_t bfm_sc5_duart_input_r();
	void bfm_sc5_duart_output_w(uint8_t data);
};

INPUT_PORTS_EXTERN( bfm_sc5 );

#endif // MAME_INCLUDES_BFM_SC5_H
