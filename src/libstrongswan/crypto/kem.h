/*
 * Copyright (C) 2019 Andreas Steffen
 * HSR Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/**
 * @defgroup kem kem
 * @{ @ingroup crypto
 */

#ifndef KEM_H_
#define KEM_H_

typedef struct kem_t kem_t;

#include <crypto/key_exchange.h>

/**
 * Implementation of a Key Encapsulation Mechanism (KEM)
 */
struct kem_t {

	/**
	 * Implements the key_exchange_t interface.
	 */
	key_exchange_t ke;

	/**
	 * Set the ciphertext received from the peer.
	 *
	 * @param value		ciphertext from peer
	 * @return			TRUE if ciphertext is successfully decripted
	 */
	bool (*set_ciphertext)(kem_t *this, chunk_t value)
		__attribute__((warn_unused_result));

	/**
	 * Get the ciphertext containing the encrypted shared secret.
	 *
	 * @param value		ciphertext
	 * @return			TRUE if shared secret could be encrypted
	 */
	bool (*get_ciphertext)(kem_t *this, chunk_t *value)
		__attribute__((warn_unused_result));

};

#endif /** KEM_H_ @}*/
