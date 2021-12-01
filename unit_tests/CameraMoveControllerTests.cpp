#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "CameraMoveController.h"

const float expectedNormalizedAngle = 0.09999;
const float expectedAngle = 35.9964;
const float angleFactor = 360;

BOOST_AUTO_TEST_CASE( TestSubtractTwoFloats ) {
	float value = SubTwoFloats(0.1, 0.00001);
	BOOST_CHECK_EQUAL(value, expectedNormalizedAngle);
	BOOST_CHECK_EQUAL(value*angleFactor, expectedNormalizedAngle*angleFactor);
	BOOST_CHECK_EQUAL(value*angleFactor, 0.09999*angleFactor);
};


BOOST_AUTO_TEST_CASE( TestForStateMachine ) {
	CameraMoveController c;
	BOOST_CHECK_EQUAL(c.GetCurrentState(), EngineState::HomePosition);
	c.StopCamera();
	BOOST_CHECK_EQUAL(c.GetCurrentState(), EngineState::Stopped);
	c.GoToHome();
	BOOST_CHECK_EQUAL(c.GetCurrentState(), EngineState::HomePosition);
};

BOOST_AUTO_TEST_CASE( TestForStateMachineMoveTests ) {
	CameraMoveController c;
	c.MoveCamera();
	BOOST_CHECK_EQUAL(c.GetCurrentPos(), 0.5);
	c.MoveCamera();
	BOOST_CHECK_EQUAL(c.GetCurrentPos(), 0.2);
};
