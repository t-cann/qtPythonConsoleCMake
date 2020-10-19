//
// src/DataArray.h
//
// (c) British Crown Owned Copyright 2019/AWE
//
// This file is part of TIO browse
// Released under the BSD 3-clause license.
// For more details see license.txt
//

#ifndef SRC_DATAARRAY_H_
#define SRC_DATAARRAY_H_

#include <typhonio.h>

#include <QVariant>
#include <string>

//! TyphonIO data array object
//!
//! Used for passing TyphonIO array data, and converting it to a QVariant as
//! required
class DataArray {
 public:
  enum ArrayType { TYPE_DATA, TYPE_SHAPE, TYPE_NODES_PER_CELL };

  //! Constructor
  //! \param[in] name is the item name
  //! \param[in] nDims is the dimensionality of the data, TIO_1D, TIO_2D, etc.
  //! \param[in] dims is a pointer to an array of dimension sizes
  //! \param[in] dataType is the TyphonIO data, TIO_INT, TIO_DOUBLE, etc.
  //! \param[in] data is a pointer to the array of data. Responsibility for
  //! deleting the data is given to the DataArray
  DataArray(const std::string &name, const TIO_Dims_t &nDims,
            const TIO_Size_t *dims, const ArrayType &ArrayType,
            const TIO_Data_t &dataType);

  //! Destructor
  ~DataArray();

  //! Getter for TyphonIO data type
  //! \return The data type as set in the constructor
  TIO_Data_t getTIODataType() const;

  //! Getter for the data array length
  //! \return The length of the data array
  TIO_Size_t getArrayLength() const;

  //! Get the size of the requested dimension
  //! \return The size of dimension given by index
  TIO_Size_t getDim(const int &index) const;

  //! Getter for name
  //! \return The name of the data
  std::string getName() const;

  //! Getter for nDims
  //! \return The number of dimensions
  int getNDims() const;

  //! Getter for the data pointer
  //! \return A void pointer to memory owned by DataArray
  void *getVoidPointer() const;

  //! Gets the data as a QVariant
  //! \param[in] index is the 1D index into the data array
  //! \return The value converted to a QVariant
  QVariant toQVariant(const int &index) const;

  //! Gets the data as a string
  //! \param[in] index is the 1D index into the data array
  //! \return The value converted to a std::string
  std::string toString(const int &index) const;

 private:
  //! Allocate memory and save pointer in m_data
  void AllocateMemory();

  //! Calculate the array length from the dimensions
  void CalculateArrayLength();

  //! Deallocate memory -- counterpart to AllocateMemory
  void DeallocateMemory();

  std::string m_name;
  TIO_Dims_t m_nDims;
  TIO_Size_t *m_dims;
  TIO_Data_t m_dataType;
  TIO_Size_t m_arrayLength;
  ArrayType m_arrayType;
  void *m_data;

  DataArray() = delete;
  DataArray(const DataArray &) = delete;
};

#endif  // SRC_DATAARRAY_H_
