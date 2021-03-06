<?php
/**
 * Copyright 2006-2017 Horde LLC (http://www.horde.org/)
 *
 * @author     Chuck Hagenbuch <chuck@horde.org>
 * @license    http://www.horde.org/licenses/bsd
 * @category   Horde
 * @package    Db
 */

/**
 * Encapsulation object for binary values to be used in SQL statements to
 * ensure proper quoting, escaping, retrieval, etc.
 *
 * @author     Chuck Hagenbuch <chuck@horde.org>
 * @license    http://www.horde.org/licenses/bsd
 * @category   Horde
 * @package    Db
 */
class Horde_Db_Value_Binary implements Horde_Db_Value
{
    /**
     * Binary value to be quoted
     *
     * @var string
     * @since Horde_Db 2.1.0
     */
    public $value;

    /**
     * Constructor
     *
     * @param string $binaryValue
     */
    public function __construct($binaryValue)
    {
        $this->value = $binaryValue;
    }

    /**
     * @param Horde_Db_Adapter $db
     */
    public function quote(Horde_Db_Adapter $db)
    {
        return $db->quoteBinary($this->value);
    }
}
