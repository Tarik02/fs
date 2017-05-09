#pragma once

#include <string>
#include <vector>

namespace fs {
	class path {
	public:
		static char PathDelim;

	private:
		std::string itemPath;
		std::string itemName;

	public:
		path();
		path(const std::string &path);
		~path();

		// Common functions
		inline std::string dir() const {
			return itemPath;
		}
		inline std::string name() const {
			return itemName;
		}
		inline std::string full_name() const {
			return dir() + PathDelim + name();
		}

		bool create();
		bool mkdir();
		bool mkdirs();
		bool remove();

		bool exists() const;
		bool is_file() const;
		bool is_directory() const;
		bool is_temponary() const;

		path parent() const;
		path &parent(const path &target);

		// Stat functions
		unsigned long createdAt();
		unsigned long modifiedAt();

		// Folder functions
		path add(const std::string &name);

		std::vector<path> list() const;

		std::string relative(const path &child) const;

		// File functions
		std::string content() const;
		bool content(const std::string &newContent);

		path &open(std::ifstream &stream);
		path &open(std::ofstream &stream);
		path &open(std::fstream &stream);

		const path &open(std::ifstream &stream) const;
		const path &open(std::ofstream &stream) const;
		const path &open(std::fstream &stream) const;

		// Operators
		path operator /(const std::string &sub) const;

		// To use as map key
		bool operator <(const path &operand) const;
	};

	path temp();
	path relative(const std::string &relative);
	std::string escape(const path &path);
	std::string escape(const std::string &path);
}
