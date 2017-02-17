#include "headers\Bone.h"

Bone::Bone() {}

void Bone::box(GLdouble width, GLdouble height, GLdouble lenght) {

	// Front
	glBegin(GL_QUADS);
	glNormal3d(0, 0, lenght / 2);
	glVertex3d(-width / 2, height / 2, lenght / 2);
	glVertex3d(width / 2, height / 2, lenght / 2);
	glVertex3d(width / 2, -height / 2, lenght / 2);
	glVertex3d(-width / 2, -height / 2, lenght / 2);
	glEnd();

	// Right
	glBegin(GL_QUADS);
	glNormal3d(-width / 2, 0, 0);
	glVertex3d(-width / 2, +height / 2, -lenght / 2);
	glVertex3d(-width / 2, +height / 2, lenght / 2);
	glVertex3d(-width / 2, -height / 2, lenght / 2);
	glVertex3d(-width / 2, -height / 2, -lenght / 2);
	glEnd();

	// Back
	glBegin(GL_QUADS);
	glNormal3d(0, 0, -lenght / 2);
	glVertex3d(width / 2, height / 2, -lenght / 2);
	glVertex3d(-width / 2, height / 2, -lenght / 2);
	glVertex3d(-width / 2, -height / 2, -lenght / 2);
	glVertex3d(width / 2, -height / 2, -lenght / 2);
	glEnd();

	// Left
	glBegin(GL_QUADS);
	glNormal3d(width / 2, 0, 0);
	glVertex3d(width / 2, height / 2, lenght / 2);
	glVertex3d(width / 2, height / 2, -lenght / 2);
	glVertex3d(width / 2, -height / 2, -lenght / 2);
	glVertex3d(width / 2, -height / 2, lenght / 2);
	glEnd();

	// Top
	glBegin(GL_QUADS);
	glNormal3d(0, height / 2, 0);
	glVertex3d(-width / 2, height / 2, -lenght / 2);
	glVertex3d(width / 2, height / 2, -lenght / 2);
	glVertex3d(width / 2, height / 2, lenght / 2);
	glVertex3d(-width / 2, height / 2, lenght / 2);
	glEnd();


	// Bottom
	glBegin(GL_QUADS);
	glNormal3d(0, -height / 2, 0);
	glVertex3d(-width / 2, -height / 2, lenght / 2);
	glVertex3d(width / 2, -height / 2, lenght / 2);
	glVertex3d(width / 2, -height / 2, -lenght / 2);
	glVertex3d(-width / 2, -height / 2, -lenght / 2);
	glEnd();


}

void Bone::box(GLdouble width, GLdouble height, GLdouble lenght, GLint* colors) {

	// Front
	glBegin(GL_QUADS);
	glNormal3d(0, 0, lenght / 2);
	glColor3ub(colors[0], colors[1], colors[2]);
	glVertex3d(-width / 2, height / 2, lenght / 2);
	glVertex3d(width / 2, height / 2, lenght / 2);
	glVertex3d(width / 2, -height / 2, lenght / 2);
	glVertex3d(-width / 2, -height / 2, lenght / 2);
	glEnd();

	// Right
	glBegin(GL_QUADS);
	glNormal3d(-width / 2, 0, 0);
	glColor3ub(colors[3], colors[4], colors[5]);
	glVertex3d(-width / 2, height / 2, -lenght / 2);
	glVertex3d(-width / 2, height / 2, lenght / 2);
	glVertex3d(-width / 2, -height / 2, lenght / 2);
	glVertex3d(-width / 2, -height / 2, -lenght / 2);
	glEnd();

	// Back
	glBegin(GL_QUADS);
	glNormal3d(0, 0, -lenght / 2);
	glColor3ub(colors[6], colors[7], colors[8]);
	glVertex3d(width / 2, height / 2, -lenght / 2);
	glVertex3d(-width / 2, height / 2, -lenght / 2);
	glVertex3d(-width / 2, -height / 2, -lenght / 2);
	glVertex3d(width / 2, -height / 2, -lenght / 2);
	glEnd();

	// Left
	glBegin(GL_QUADS);
	glNormal3d(width / 2, 0, 0);
	glColor3ub(colors[9], colors[10], colors[11]);
	glVertex3d(width / 2, height / 2, lenght / 2);
	glVertex3d(width / 2, height / 2, -lenght / 2);
	glVertex3d(width / 2, -height / 2, -lenght / 2);
	glVertex3d(width / 2, -height / 2, lenght / 2);
	glEnd();

	// Top
	glBegin(GL_QUADS);
	glNormal3d(0, height / 2, 0);
	glColor3ub(colors[12], colors[13], colors[14]);
	glVertex3d(-width / 2, height / 2, -lenght / 2);
	glVertex3d(+width / 2, height / 2, -lenght / 2);
	glVertex3d(+width / 2, height / 2, lenght / 2);
	glVertex3d(-width / 2, height / 2, lenght / 2);
	glEnd();


	// Bottom
	glBegin(GL_QUADS);
	glNormal3d(0, -height / 2, 0);
	glColor3ub(colors[15], colors[16], colors[17]);
	glVertex3d(-width / 2, -height / 2, lenght / 2);
	glVertex3d(width / 2, -height / 2, lenght / 2);
	glVertex3d(width / 2, -height / 2, -lenght / 2);
	glVertex3d(-width / 2, -height / 2, -lenght / 2);
	glEnd();


}

void Bone::sphere(GLdouble radius, GLint slices, GLint stacks) {

	// the sphere is made by quads, each quad is composed by two triangles
	glBegin(GL_TRIANGLES);
	for (GLfloat lat = 0; lat < stacks; lat += 1.f)
		for (GLfloat lon = 0; lon < slices; lon += 1.f)
		{
			Vector3 p;

			// -- first triangle
			p = spherePoint(lat, lon, stacks, slices, radius);
			glNormal3d(p.x, p.y, p.z);
			glVertex3d(p.x, p.y, p.z);

			p = spherePoint(lat + 1, lon, stacks, slices, radius);
			glNormal3d(p.x, p.y, p.z);
			glVertex3d(p.x, p.y, p.z);

			p = spherePoint(lat + 1, lon + 1, stacks, slices, radius);
			glNormal3d(p.x, p.y, p.z);
			glVertex3d(p.x, p.y, p.z);


			// -- second triangle
			p = spherePoint(lat, lon, stacks, slices, radius);
			glNormal3d(p.x, p.y, p.z);
			glVertex3d(p.x, p.y, p.z);

			p = spherePoint(lat + 1, lon + 1, stacks, slices, radius);
			glNormal3d(p.x, p.y, p.z);
			glVertex3d(p.x, p.y, p.z);

			p = spherePoint(lat, lon + 1, stacks, slices, radius);
			glNormal3d(p.x, p.y, p.z);
			glVertex3d(p.x, p.y, p.z);

		}
	glEnd();
}

void Bone::sphere(GLdouble radius, GLint slices, GLint stacks, GLint* colors) {
	int color = 1;
	// the sphere is made by quads, each quad is composed by two triangles
	glBegin(GL_TRIANGLES);
	for (GLfloat lat = 0; lat < stacks; lat += 1.f) {
		if (color == 1) {
			glColor3ub(colors[0], colors[1], colors[2]);
			color = 2;
		}
		else {
			glColor3ub(colors[3], colors[4], colors[5]);
			color = 1;
		}
		for (GLfloat lon = 0; lon < slices; lon += 1.f) {
			Vector3 p;
			if (color == 1) {
				glColor3ub(colors[0], colors[1], colors[2]);
				color = 2;
			}
			else {
				glColor3ub(colors[3], colors[4], colors[5]);
				color = 1;
			}
			// -- first triangle
			p = spherePoint(lat, lon, stacks, slices, radius);
			glNormal3d(p.x, p.y, p.z);
			glVertex3d(p.x, p.y, p.z);

			p = spherePoint(lat + 1, lon, stacks, slices, radius);
			glNormal3d(p.x, p.y, p.z);
			glVertex3d(p.x, p.y, p.z);

			p = spherePoint(lat + 1, lon + 1, stacks, slices, radius);
			glNormal3d(p.x, p.y, p.z);
			glVertex3d(p.x, p.y, p.z);


			// -- second triangle

			p = spherePoint(lat, lon, stacks, slices, radius);
			glNormal3d(p.x, p.y, p.z);
			glVertex3d(p.x, p.y, p.z);

			p = spherePoint(lat + 1, lon + 1, stacks, slices, radius);
			glNormal3d(p.x, p.y, p.z);
			glVertex3d(p.x, p.y, p.z);

			p = spherePoint(lat, lon + 1, stacks, slices, radius);
			glNormal3d(p.x, p.y, p.z);
			glVertex3d(p.x, p.y, p.z);

		}
	}
	glEnd();
}

Vector3 Bone::spherePoint(GLdouble lat, GLdouble lon, GLdouble n_lat, GLdouble n_lon,
	GLdouble radius) {
	return Vector3(
		radius*sin(PI * (lat / n_lat)) * cos(2 * PI * (lon / n_lon)),
		radius*sin(PI * (lat / n_lat)) * sin(2 * PI * (lon / n_lon)),
		radius*cos(PI * (lat / n_lat)));
}