/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:50:44 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/23 23:39:00 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <chrono>
#include <thread>

/*int main()*/
/*{*/
/*    std::cout << "hello world ";  // This may remain in the buffer*/
/*    std::this_thread::sleep_for(std::chrono::seconds(2));  // Delay to simulate buffering*/
/*    std::cout << std::flush;  // Force the buffer to flush after the delay*/
/**/
/*    // If there was no flushing, "hello world " will only appear after 2 seconds*/
/*    std::cout << "\nDone!" << std::endl;  // Newline + flush*/
/*    return 0;*/
/*}*/

#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::cout << "hello world\n";  // The newline may trigger a flush
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Delay to simulate buffering
    
    std::cout << "Done!" << std::endl;
    return 0;
}

