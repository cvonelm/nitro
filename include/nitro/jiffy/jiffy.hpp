/*
 * Copyright (c) 2015-2017, Technische Universität Dresden, Germany
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions
 *    and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to
 *    endorse or promote products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 * WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

namespace nitro
{
namespace jiffy
{
    class Jiffy
    {
    public:
        Jiffy();

        Jiffy(std::chrono::system_clock::time_point tp);

        Jiffy(const std::string& date,
              const std::string& format = std::string("%Y-%m-%dT%H:%M:%S%z"));

    public:
        std::string format(std::string fmt) const;

        std::string isoformat() const
        {
            return format("%Y-%m-%dT%H:%M:%S.%f%z");
        }

        operator std::string() const
        {
            return isoformat();
        }

    public:
        int year() const
        {
            return tm_data_.tm_year + 1900;
        }

        int month() const
        {
            return tm_data_.tm_mon + 1;
        }

        int day() const
        {
            return tm_data_.tm_mday;
        }

        int hour() const
        {
            return tm_data_.tm_hour;
        }

        int minute() const
        {
            return tm_data_.tm_min;
        }

        int second() const
        {
            return tm_data_.tm_sec;
        }

        int microsecond() const
        {
            // this is in the range [0, 1e6), so it's fine
            return static_cast<int>(fraction_.count());
        }

    public:
        operator std::tm() const
        {
            return tm_data_;
        }

    private:
        void clear();

        std::tm tm_data_;
        std::chrono::microseconds fraction_;
    };

    inline std::ostream& operator<<(std::ostream& s, const Jiffy& j)
    {
        return s << j.isoformat();
    }
}
}