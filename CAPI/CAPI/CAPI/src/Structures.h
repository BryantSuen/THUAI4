#pragma once

#ifndef STRUCTURES_H

#define STRUCTURES_H

#include <cstdint>
#include <array>

namespace THUAI4
{

	enum class PropType : unsigned char    //��������
	{
		Null = 0,
		Bike = 1,
		Amplifier = 2,
		JinKeLa = 3,
		Rice = 4,
		NegativeFeedback = 5,
		Totem = 6,
		Phaser = 7,
		Dirt = 8,
		Attenuator = 9,
		Divider = 10
	};

	enum class ShapeType : unsigned char    //������״
	{
		Circle = 0,
		Square = 1
	};

	enum class JobType : unsigned char    //���ְҵ
	{
		Job0 = 0,
		Job1 = 1,
		Job2 = 2,
		Job3 = 3,
		Job4 = 4,
		Job5 = 5,
		Job6 = 6,
	};

	enum class BulletType : unsigned char    //�ӵ�����
	{
		Bullet0 = 0,
		Bullet1 = 1,
		Bullet2 = 2,
		Bullet3 = 3,
		Bullet4 = 4,
		Bullet5 = 5,
		Bullet6 = 6
	};

	enum class ColorType : unsigned char    //��ɫ����
	{
		None = 0,
		Color1 = 1,
		Color2 = 2,
		Color3 = 3,
		Color4 = 4,
		Invisible = 5
	};

	struct Character
	{
		bool isMoving;  //�Ƿ������ƶ�
		bool isDying;  //�Ƿ����ڸ�����
		ShapeType shapeType : 2;  //��״��Բ��
		BulletType bulletType : 4;  //�ӵ�����
		PropType propType : 4;  //��ӵ�е�������
		JobType jobType : 4;  //ְҵ����
		uint16_t lifeNum;  //�ڼ�����
		uint16_t teamID;  //����ID
		uint16_t radius;  //Բ������İ뾶������������Բ�뾶
		uint16_t maxBulletNum;  //�����������
		uint16_t bulletNum;  //��ǰ�ӵ�����

		uint32_t x;  //x����
		uint32_t y;  //y����
		uint32_t moveSpeed;  //�ƶ��ٶ�
		uint32_t ap;  //������
		uint32_t maxHp;  //�������ֵ
		uint32_t hp;  //��ǰ����ֵ
		uint32_t CD;  //�����ȴʱ��
		int64_t guid;  //Global Unique Identifier
		double facingDirection;  //�ƶ�����
	};

	struct Wall
	{
		ShapeType shapeType : 2;  //��״�������Σ�
		uint16_t radius;  //Բ������İ뾶������������Բ�뾶
		uint32_t x;  //x����
		uint32_t y;  //y����
		int64_t guid;  //Global Unique Identifier
	};

	struct Prop
	{
		bool isMoving;  //�Ƿ������ƶ�
		bool isLaid;  //�Ƿ��ѱ����ã�ѡ���ܿ�����һ��û�����ã�
		ShapeType shapeType : 2;  //��״
		PropType propType : 4;  //��������
		uint16_t radius;  //Բ������İ뾶������������Բ�뾶
		uint32_t x;  //x����
		uint32_t y;  //y����
		uint32_t moveSpeed;  //�ƶ��ٶ�
		int64_t guid;  //Global Unique Identifier
		double facingDirection;  //�ƶ�����
	};

	struct Bullet
	{
		bool isMoving;  //�Ƿ����ƶ����ǣ�
		ShapeType shapeType : 2;  //��״��Բ��
		BulletType bulletType : 4;  //�ӵ�����
		uint16_t radius;  //Բ������İ뾶������������Բ�뾶
		uint16_t teamID;  //��������
		uint32_t x;  //x����
		uint32_t y;  //y����
		uint32_t moveSpeed;  //�ƶ��ٶ�
		uint32_t ap;  //������
		int64_t guid;  //Global Unique Identifier
		double facingDirection;  //�ƶ�����
	};

	struct BirthPoint
	{
		ShapeType shapeType;  //��״��Բ��
		uint16_t teamID;  //����ID
		uint16_t radius;  //Բ������İ뾶������������Բ�뾶
		uint32_t x;  //x����
		uint32_t y;  //y����
		int64_t guid;  //Global Unique Identifier
	};

}

#endif //!STRUCTURES_H
