/* File.h
Copyright (c) 2015 by Michael Zahniser

Endless Sky is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

Endless Sky is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#ifndef FILE_H_
#define FILE_H_

#include <cstdio>
#include <string>



// RAII wrapper for FILE, to make sure it gets closed if an error occurs.
class File {
public:
	// Default constructor.
	File() noexcept = default;
	
	// Explicit constructors can't be used for implicit conversion or copy-initialization.
	explicit File(const std::string &path, bool write = false);
	
	// 'delete' disables the use of a method, as here with the copy constructor.
	File(const File &) = delete;
	
	// '&&' indicates an r-value, a value with no memory address (e.g. '5', '(b+2)').
	// 'noexcept' evaluates to TRUE if the expression throws no errors.
	File(File &&other) noexcept;
	
	// 
	~File() noexcept;
	
	// Do not allow copying the FILE pointer.
	File &operator=(const File &) = delete;
	
	// Move assignment is OK though.
	File &operator=(File &&) noexcept;
	
	operator bool() const;
	operator FILE*() const;
	
private:
	FILE *file = nullptr;
};



#endif
