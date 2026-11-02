#pragma once

#include <stdexcept>
#include <string>
#include <utility>

namespace OBS {

enum class InitError {
	UserDirectories,
	GlobalConfig,
	BasicConfig,
	Locale,
	Theme,
	LocaleList,
	CoreModules,
	Audio,
	Video,
	Service,
	ProfileDirectories,
	DefaultTransitions,
};

class InitException : public std::runtime_error {
public:
	InitException(InitError error, std::string message = {})
		: std::runtime_error(message), error_(error), message_(std::move(message))
	{
	}

	InitError error() const noexcept { return error_; }
	const std::string &message() const noexcept { return message_; }

private:
	InitError error_;
	std::string message_;
};

} // namespace OBS