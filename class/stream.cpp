class ostream : public ios {
	public:
		// Overloading the insertion operator for different types
		ostream& operator<<(int value) {
			// Convert the integer to string and write it to the stream
			this->write_int(value);
			return *this;  // Return the stream to allow chaining
		}

		ostream& operator<<(const char* str) {
			// Write the string to the stream
			this->write_string(str);
			return *this;
		}

		ostream& operator<<(double value) {
			// Convert the double to string and write it to the stream
			this->write_double(value);
			return *this;
		}

		// Function to handle std::endl, which is a manipulator
		ostream& operator<<(ostream& (*func)(ostream&)) {
			return func(*this);
		}

		// A function to handle flushing the buffer, usually tied to endl
		ostream& flush() {
			// Code to flush the output buffer
			this->flush_buffer();
			return *this;
		}

	protected:
		// These would be internal methods for actual output
		void write_int(int value) {
			// Code to convert the int to characters and write to the output device
		}

		void write_string(const char* str) {
			// Code to write the string to the output device
		}

		void write_double(double value) {
			// Code to convert double to characters and write to the output device
		}

		void flush_buffer() {
			// Code to flush the internal buffer to the output device
		}
};

// Defining std::cout as an instance of ostream
ostream cout;  // Standard output stream

