#pragma once

#include <osgGA/CameraManipulator>
#include <osg/ShapeDrawable>
#include <osgViewer/Viewer>
#include <osg/MatrixTransform>

class CDriveManupulator : public osgGA::CameraManipulator
{
public:
	CDriveManupulator();

	osg::Node* getBallNode() { return m_rpMtBall.get(); }

	//������д���ĸ��������������
	virtual void setByMatrix(const osg::Matrixd& matrix) {}

	virtual void setByInverseMatrix(const osg::Matrixd& matrix) {}

	virtual osg::Matrixd getMatrix() const
	{
		osg::Matrixd mat;
		mat.makeRotate(m_vecRotation.x(), osg::Vec3(1.0, 0.0, 0.0),
			m_vecRotation.y(), osg::Vec3(0.0, 1.0, 0.0),
			m_vecRotation.z(), osg::Vec3(0.0, 0.0, 1.0));
		return mat * osg::Matrixd::translate(m_vecPosition);
	}

	virtual osg::Matrixd getInverseMatrix() const
	{
		osg::Matrixd mat;
		mat.makeRotate(m_vecRotation.x(), osg::Vec3(1.0, 0.0, 0.0),
			m_vecRotation.y(), osg::Vec3(0.0, 1.0, 0.0),
			m_vecRotation.z(), osg::Vec3(0.0, 0.0, 1.0));
		return osg::Matrixd::inverse(mat * osg::Matrixd::translate(m_vecPosition));
	}

	/**
	  * @brief ��Ҫ˵��������ƶ�����
	  * @note ��ϸ˵����
	  * @param ����1 [in/out/inout]���ƶ�����
	  * @return ����ֵ�Լ�˵����
	*/
	void ChangePosition(osg::Vec3 vec3Delta);

	/**
	  * @brief ��Ҫ˵����С��ǰ���ƶ�����
	  * @note ��ϸ˵����
	  * @param ����1 [in/out/inout]���ƶ�����
	  * @return ����ֵ�Լ�˵����
	*/
	void ChangePositionCar(osg::Vec3 vec3Delta);

	/**
	  * @brief ��Ҫ˵����С�������ƶ�����
	  * @note ��ϸ˵����
	  * @param ����1 [in/out/inout]���ƶ�����
	  * @return ����ֵ�Լ�˵����
	*/
	void ChangePositionCarLeftRight(osg::Vec3 vec3Delta);

	/**
	  * @brief ��Ҫ˵������д�¼�����
	  * @note ��ϸ˵����
	  * @return ����ֵ�Լ�˵����
	*/
	bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

private:
	osg::Vec3							m_vecPosition;		//���λ��
	osg::Vec3							m_vecRotation;		//�����̬
	float								m_fMoveSpeed;		//�ƶ��ٶ�
	float								m_fAnglg;			//�仯�Ƕ�
	osg::Vec3							m_vecBallPosition;	//С��λ��
	osg::ref_ptr<osg::MatrixTransform>	m_rpMtBall;			//С�����


};