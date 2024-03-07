//
// File: joaat.h
//
// Copyright (C) 2023 ranstar74. All rights violated.
//
// Part of "Rage Am" Research Project.
//
#pragma once

#include "app/common/types.h"
#include "app/helpers/cstr.h"

namespace rage
{
	using atHashValue = u32;

	// Jenkins one at a time hash
	// Template isn't used because it will break implicit cast operators

	constexpr u32 joaat(const char* str, bool lowerCase = true)
	{
		u32 i = 0;
		u32 hash = 0;
		while (str[i] != '\0') {
			hash += lowerCase ? cstr::tolower(str[i++]) : str[i++];
			hash += hash << 10;
			hash ^= hash >> 6;
		}
		hash += hash << 3;
		hash ^= hash >> 11;
		hash += hash << 15;
		return hash;
	}

	constexpr u32 joaat(const wchar_t* str, bool lowerCase = true)
	{
		u32 i = 0;
		u32 hash = 0;
		while (str[i] != '\0') {
			hash += lowerCase ? cstr::towlower(str[i++]) : str[i++]; // TODO: This currently doesn't support unicode and we need it for UI
			hash += hash << 10;
			hash ^= hash >> 6;
		}
		hash += hash << 3;
		hash ^= hash >> 11;
		hash += hash << 15;
		return hash;
	}

	// Although it's not very good idea to compare hash to '0' but this is what rage does
	inline bool atIsNullHash(atHashValue hash) { return hash == 0 || hash == joaat("null"); }
}
