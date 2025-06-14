/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:07:45 by sabe              #+#    #+#             */
/*   Updated: 2025/06/14 16:07:52 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    // ClapTrap インスタンスを生成
    ClapTrap clap("CL4P-TP");

    std::cout << "\n-- attack() のテスト --\n";
    clap.attack("Bandit");    // 攻撃してエナジー1消費

    std::cout << "\n-- takeDamage() のテスト --\n";
    clap.takeDamage(3);       // ヒットポイントを3減少
    clap.takeDamage(8);       // ヒットポイントが0以下になり、以降死んでいる状態

    std::cout << "\n-- beRepaired() のテスト（ヒットポイント0の状態） --\n";
    clap.beRepaired(5);       // HPが0なので修復できないはず

    // もう一体作って、エナジー切れの動作も確認
    ClapTrap newbie("Newbie");
    std::cout << "\n-- エナジー切れテスト --\n";
    for (int i = 0; i < 12; ++i) {
        std::cout << "Attempt " << (i+1) << ": ";
        newbie.attack("Target");
    }

    return 0;
}
