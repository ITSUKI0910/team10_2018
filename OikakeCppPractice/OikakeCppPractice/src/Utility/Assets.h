#pragma once

/**
 * @file Assets.h
 * @brief �Q�[�����Ŏg�p����A�Z�b�g�̒�`�t�@�C��
 * @author ���]
 * @date 2017/2/23
 */

 //! Assets�̖��O���
namespace Assets {
	/**
	* @enum Texture
	* �g�p����e�N�X�`���̒�`
	*/
	enum class Texture {
		//Background,
		//Map,
		//Player,
		//Enemy,
		//Number,
		//Title,
		//Result

		// �}�b�v�`�b�v�����p
		NormalTile,
		Hole,			//��
		Tofu,
		OnePlayerField,
		TwoPlayerField,

		Title,

		None,			//�͈͊O�Q�Ɨp�^��NULL
	};
}