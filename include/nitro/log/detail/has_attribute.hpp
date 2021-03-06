/*
 * Copyright (c) 2015-2016, Technische Universität Dresden, Germany
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

#ifndef INCLUDE_NITRO_LOG_DETAIL_HAS_ATTRIBUTE_HPP
#define INCLUDE_NITRO_LOG_DETAIL_HAS_ATTRIBUTE_HPP

#include <nitro/meta/variadic.hpp>

namespace nitro
{
namespace log
{
    namespace detail
    {

        template <typename... Attributes>
        struct has_attribute;

        template <typename Attribute, typename... Attributes, template <typename...> class Record>
        struct has_attribute<Attribute, Record<Attributes...>>
        {
            static const bool value =
                nitro::meta::is_variadic_member<Attribute, Attributes...>::value;
        };

        template <template <typename...> class Attribute, typename... Attributes>
        struct has_attribute_specialization;

        template <template <typename...> class Attribute, typename... Attributes,
                  template <typename...> class Record>
        struct has_attribute_specialization<Attribute, Record<Attributes...>>
        {
            static const bool value =
                nitro::meta::is_variadic_member_specialization<Attribute, Attributes...>::value;
        };
    } // namespace detail
} // namespace log
} // namespace nitro

#endif // INCLUDE_NITRO_LOG_DETAIL_HAS_ATTRIBUTE_HPP
