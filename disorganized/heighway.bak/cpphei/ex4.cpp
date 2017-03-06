  struct MyVertex
  {
    float x, y, z;        //Vertex
  };
 
  MyVertex pvertex[3];
  //VERTEX 0
  pvertex[0].x = 0.0;
  pvertex[0].y = 0.0;
  pvertex[0].z = 0.0;
  //VERTEX 1
  pvertex[1].x = 1.0;
  pvertex[1].y = 0.0;
  pvertex[1].z = 0.0;
  //VERTEX 2
  pvertex[2].x = 0.0;
  pvertex[2].y = 1.0;
  pvertex[2].z = 0.0;
 


  glGenBuffers(1, VertexVBOID);
  glBindBuffer(GL_ARRAY_BUFFER, VertexVBOID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(MyVertex)*3, &pvertex[0].x, GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, VertexVBOID);

int verticesBufferStream = 0;

  glEnableVertexAttribArray(verticesBufferStream);
  glVertexAttribPointer(verticesBufferStream, 3, GL_FLOAT, GL_FALSE, sizeof(MyVertex), BUFFER_OFFSET(0));


 
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexVBOID);
  //To render, we can either use glDrawElements or glDrawRangeElements
  //The is the number of indices. 3 indices needed to make a single triangle
  glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, BUFFER_OFFSET(0));   //The starting point of the IBO
  //0 and 3 are the first and last vertices
  //glDrawRangeElements(GL_TRIANGLES, 0, 3, 3, GL_UNSIGNED_SHORT, BUFFER_OFFSET(0));   //The starting point of the IBO
  //glDrawRangeElements may or may not give a performance advantage over glDrawElements

